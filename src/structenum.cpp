#include "structenum.h"

// non necessita di typedef (anche enum!)
enum class Colore { NERO, ROSSO, VERDE, GIALLO };

void foo(Colore c) {}

void bar(int c) {
  if (c == 0) {
  }
}

struct Scatola {}; // non necessita di typedef

void baz(const Scatola &s) {}

void structenum_run() {
  Colore r{Colore::ROSSO};
  foo(r);
  // bar(r); // Genera errore con enum class
}