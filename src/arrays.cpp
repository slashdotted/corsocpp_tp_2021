#include "arrays.h"
#include <iostream>

void arrays_run() {
  int valori[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto i{0}; i < 9; ++i) {
    std::cout << valori[i] << '\n';
  }

  for (int i : valori) {
    std::cout << i << '\n';
  }
}