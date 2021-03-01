#include "variables.h"

double pi_val() { return 3.14; }

void variables_run() {
  auto u{0};

  u = 9;

  // C-style
  auto v = 10;
  auto x = 42;

  // C++ (pre-11)
  auto y(77);

  // C++ 11
  auto e{13};
  auto f{42};

  auto pi{3.14};
  auto w{false};
  auto pi2{pi_val()};
}