#include "raii.h"
#include <iostream>
#include <string>

struct A {
  A() { std::cout << "Costruzione di A\n"; }

  ~A() { std::cout << "Distruzione di A\n"; }
};

struct B {
  B(const std::string &n)
      : nome{n}, a{new A} { // RAII Resource Acquisition Is Initialization
                            // (acquisisco nel costruttore)
    std::cout << "Costruzione di B " << nome << '\n';
  }

  // Costruttore di copia
  B(const B &o)
      : nome{o.nome}, a{new A{*o.a}} { // Copio il valore dei campi da o
    std::cout << "Costruzione di una copia B " << nome << '\n';
  }

  // Operatore di assegnamento di copia
  B &operator=(const B &o) {
    nome = o.nome; // copio il valore
    *a = *o.a;     // copio il valore
    std::cout << "Assegnamento di una copia B " << nome << '\n';
    return *this;
  }

  ~B() {
    std::cout << "Distruzione di B " << nome << '\n';
    delete a; // RAII Resource Acquisition Is Initialization (dealloco nel
              // distruttore)
  }
  A *a;
  std::string nome;
};

struct C {
  C(const std::string &n) : nome{n} {
    std::cout << "Costruzione di C " << nome << '\n';
  }
  A a;
  std::string nome;
};

struct D {
  D(C &c) : ex_c{c} {}
  C &ex_c;
};

void foo(B b) {}

void raii_run() {
  B aldo{"Aldo"};
  B giovanni{"Giovanni"};

  aldo = giovanni; // crea copia! (operatore di assegnamento di copia)
  foo(aldo);       // crea copia! (Costruttore di copia)
  B giacomo{aldo}; // crea copia! (Costruttore di copia)
  // Senza costruttore / operatore di assegnamento di copia:
  // 1. aldo e giovanni e giacomo condividono la stessa allocazione (A) sullo
  // heap --> double
  // 2. free la memoria allocata da aldo / giacomo sullo heap non è più
  // raggiungibile / deallocabile
}