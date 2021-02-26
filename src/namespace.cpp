#include "namespace.h"
#include <iostream>

// using namespace std;
namespace s = std;

int x{15};
void f() {}

namespace supsi {
namespace dti {
int x{5};
void f() { std::cout << "supsi::dti::f()\n"; }
} // namespace dti
} // namespace supsi

namespace usi {
int x{15};
void f() {
  ::f(); // Versione del namespace globale
}
} // namespace usi

namespace std {
int x{15};
void f() { std::cout << "std::f()\n"; }
} // namespace std

namespace d = supsi::dti;
namespace u = usi;

void namespace_run() {
  using std::cout;
  using std::endl;
  cout << "Ciao mondo" << endl;
  s::f();
  d::f();
  u::f();
}
