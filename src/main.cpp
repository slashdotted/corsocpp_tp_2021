#include "esempio_struct.h"
#include <iostream>

void stampa(const Frazione &f) { f.scrivi(); }

void debug(const Frazione &f) {
  std::cout << "debug: num=" << f.num << " den=" << f.den << '\n';
}

int main() {
  Frazione f;
  {                   // default 0/1
    Frazione g{5, 7}; // 5/7
  }

  std::cout << Frazione::numero_istanze() << '\n';
  Frazione h{8}; // 8/1
  debug(h);
  auto *j{new Frazione};
  std::cout << Frazione::numero_istanze() << '\n';
  // f.numeratore(5);
  // f.denominatore(7);
  // f.den = 0;
  delete j;
  // f.num = 0;
  stampa(f);
  std::cout << Frazione::numero_istanze() << '\n';
  f.numeratore();
  Frazione::numero_istanze();
  return 0;
}