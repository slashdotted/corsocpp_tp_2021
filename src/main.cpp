#include <iostream>
#include "mylist.h"
#include <typeinfo>

using std::cout;

template<typename X, typename Y>
struct MioTipo {
  X x;
  Y y;
};

template<typename X = int, typename Y = bool>
struct MioTipoConTipiDefault {
  X x;
  Y y;

  void tipi() const {
    cout << "X=" << typeid(x).name() << " Y=" << typeid(y).name() << '\n';
  }
};

int main() {
  MioTipoConTipiDefault<int, double> k;
  k.tipi();
  MioTipoConTipiDefault<int> p;
  p.tipi();
  MioTipoConTipiDefault<> a;
  a.tipi();

  MyList<int, 10> ml;
  MyList<int, 15> ql;
  cout << typeid(ml).name() << " - " << typeid(ql).name() << '\n';
  MyList<double, 6> dl;
}