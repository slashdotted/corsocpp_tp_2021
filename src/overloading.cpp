#include "overloading.h"
#include <iostream>
using namespace std;

class Example {
public:
  void f(double x) { cout << "f(double x)" << endl; }
  void f(int x) // Same scope -> Overload of f
  {
    cout << "f(int x)" << endl;
  }
};

void overloading_run() {
  Example e;
  e.f(3.2);
  e.f(3);
}
