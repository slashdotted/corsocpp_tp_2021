#include "heap.h"

void on_stack() {
  auto non_ptr{15};
  auto non_ptr2{25};
  auto ptr3{0};

  double non_ptr4;
  double non_ptr5;
  double non_ptr6;
}

void heap_run() {
  auto *ptr{new int{15}};
  int *ptr2{new int{25}};

  // Null pointer
  int *ptr3{nullptr};

  auto *ptr4{new double};
  double *ptr5{new double};
  auto ptr6{new double};
  *ptr6 = 67;

  auto ptr7{new double[20]}; // allocazione array

  delete ptr;
  delete ptr2;
  delete ptr3;
  delete ptr4;
  delete ptr5;
  delete ptr6;
  delete[] ptr7; // deallocazione array
}