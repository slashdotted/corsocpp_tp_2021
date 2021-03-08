#include "esempio_struct.h"
#include <iostream>

int Frazione::istanze = 0;

Frazione::Frazione(int n, int d) : num{n}, den{d} {
  std::cout << "costruzione di ";
  scrivi();
  ++istanze;
}

Frazione::Frazione() : Frazione{0, 1} {} // Chiamata a un costruttore delegato

Frazione::~Frazione() {
  std::cout << "distruzione di ";
  scrivi();
  --istanze;
}

void Frazione::scrivi() const { std::cout << num << '/' << den << '\n'; }

int Frazione::numeratore() const {
  // return this->num;
  return num;
}
void Frazione::numeratore(int valore) { num = valore; }

// int Frazione::denominatore() const { return den; }
// void Frazione::denominatore(int valore) { den = valore; }