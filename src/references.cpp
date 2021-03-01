#include "references.h"
#include <iostream>

// **************************************
// ESEMPI DI PASSAGGIO DI PARAMETRI
// **************************************

static void f(int x) { // Per valore
  ++x;                 // modifica copia
}

static void g(int *x) { // Puntatore (per valore)
  ++(*x);
}

static void h(int &x) { // Per riferimento
  ++x;
}

// **************************************
// ESEMPI DI UTILIZZO DEI RIFERIMENTI
// **************************************

// Swap "classico" con puntatori
static void swap(int *a, int *b) {
  int t{*a};
  *a = *b;
  *b = t;
}

// Swap con riferimenti
static void swap(int &a, int &b) {
  int t{a};
  a = b;
  b = t;
}

// Ritorno di riferimenti
int &ritorno(int &x) { return x; }

// Ritorno di riferimenti a valori temporanei: ERRORE!
// int& ritorno2(int& x) {
//    return x+1;
// }

// Esempio di accesso agli elementi di un array
static void esempio_array() {
  int mioarray[]{1, 2, 3, 4, 5, 6};
  std::cout << "Per copia:\n";
  for (auto x : mioarray) {
    std::cout << x << '\n'; // x è una copia
  }
  std::cout << "Per riferimento:\n";
  for (auto &x : mioarray) {
    ++x;
    std::cout << x << '\n'; // x è un riferimento
  }
  std::cout << "Per riferimento constante:\n";
  for (const auto &x : mioarray) {
    std::cout << x << '\n'; // x è un riferimento costante
  }
}

// Il passaggio di valori temporanei (R-Value) per riferimento
// è possibile se il parametro è const
static void foo(const int &z) { std::cout << z << '\n'; }

// Questa funzione accetta solo L-Value
static void foo2(int &z) { std::cout << z << '\n'; }

static int bar() { return 42; }

void references_run() {
  int myvar{1};
  std::cout << "myvar=" << myvar << '\n';
  f(myvar);
  std::cout << "myvar=" << myvar << '\n';
  g(&myvar);
  std::cout << "myvar=" << myvar << '\n';
  h(myvar);
  std::cout << "myvar=" << myvar << '\n';
  foo(myvar);
  foo(13);
  foo(bar());

  // myvar L-Value
  // bar() R-Value
  // 13 R-Value
  myvar = bar();
  myvar = 13;
  esempio_array();
}