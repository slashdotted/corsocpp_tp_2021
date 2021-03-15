#include "esempio_struct.h"
#include "raii.h"
#include <iostream>

void stampa(const Frazione &f) { f.scrivi(); }

void debug(const Frazione &f) {
  (((((std::cout << "debug: num=") << f.num) << " den=") << f.den) << '\n');
}

// Overload di << per std::cout
std::ostream &operator<<(std::ostream &o, const Frazione &f) {
  o << f.numeratore() << '/' << f.denominatore();
  return o;
}

// Copia esplicita
/*Frazione operator+(const Frazione &a, const Frazione &b) {
  auto t{a};
  return t += b;
}*/

// Copia implicita (passaggio per valore) <-- preferibile
Frazione operator-(Frazione a, const Frazione &b) { return a -= b; }

Frazione operator-(const Frazione &a) {
  return {-a.numeratore(), a.denominatore()};
}

struct Tipo {
  explicit Tipo(int precisione) {}
};

void foo(Frazione x) {}
void bar(Tipo x) {}
void baz(double d) {}

int main() { raii_run(); }