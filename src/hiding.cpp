#include "hiding.h"
#include <iostream>

using namespace std;

class Base {
public:
  virtual void f(double x) { cout << "Base::f(double x)" << endl; }
};

class Derived : public Base {
public:
  // This is not an override of Base::f (-> different signature)
  // and it's not an overload (-> different scope)
  void f(int x) { cout << "Derived::f(int x)" << endl; }
};

void hiding_run() {
  Derived e;
  e.f(3.2);
  e.f(3);
}