#include "esempio_struct.h"
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
Frazione operator+(const Frazione &a, const Frazione &b) {
  auto t{a};
  return t += b;
}

// Copia implicita (passaggio per valore) <-- preferibile
Frazione operator-(Frazione a, const Frazione &b) { return a -= b; }

Frazione operator-(const Frazione &a) {
  return {-a.numeratore(), a.denominatore()};
}

int main() {
  Frazione f;
  {                   // default 0/1
    Frazione g{5, 7}; // 5/7
  }
  std::cout << Frazione::numero_istanze() << '\n';
  Frazione h{8}; // 8/1
  f += h;
  auto o = f + h;
  auto p = f - h;
  auto q = -f;
  // debug(h);
  std::cout << h << '\n';
  auto *j{new Frazione};
  std::cout << Frazione::numero_istanze() << '\n';
  // f.numeratore(5);
  // f.denominatore(7);
  // f.den = 0;
  delete j;
  // f.num = 0;
  // stampa(f);
  std::cout << f << '\n';
  std::cout << Frazione::numero_istanze() << '\n';
  f.numeratore();
  Frazione::numero_istanze();
  return 0;
}