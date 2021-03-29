#include "overriding.h"
#include <iostream>

using namespace std;

class Base {
public:
  virtual void f(double x) { cout << "Base::f(double x)" << endl; }
};
class Derived : public Base {
public:
  // overriding f from Base (same signature!)
  void f(double x) { cout << "Derived::f(double x)" << endl; }
};

void overriding_run() {
  Derived e;
  e.f(3.2);
  e.f(3);
}