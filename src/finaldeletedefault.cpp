#include "finaldeletedefault.h"

class Base final {};

/* Error! Cannot derive Base
class Derived : public Base
{
};
*/

class Base2 {
public:
  virtual void f() final {}
};
class Derived2 : public Base2 {
public:
  // Error! Cannot override f()
  // void f() {}
};

class Example {
public:
  Example() = default; // Example is default-constructible
  Example(const Example &) = delete;
  Example &operator=(const Example &) = delete;
};

void foo(Example v) {}

struct Copiabile {
  Copiabile() = default;
  Copiabile(const Copiabile&) {
    /* ... */
  }
  Copiabile& operator=(const Copiabile&) { return *this;}
  ~Copiabile() = default;
};

void finaldeletedefault_run() {
  Example e;
  Example f;
  Copiabile c;
  // e = f;  // Error: copy assignment operator has been deleted
  // foo(e); // Error: copy constructor has been deleted
}



