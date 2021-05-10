#include <iostream>
#include "mylist.h"
#include <typeinfo>

using std::cout;

template <typename Tipo>
void stampaTipo(Tipo t) {
  cout << typeid(t).name() << '\n';
}

template <typename X>
void stampaValore(X v) {
  cout << "Valore: " << v << '\n';
}

template <typename X, typename Y = int>
struct stampante {
  void stampa(X x, Y y) {
    cout << "Valore: " << x  << y << '\n'; 
  }
};

// specializzazione per puntatori
template <typename X, typename Y>
struct stampante<X*,Y*> {
  void stampa(X* x, Y* y) {
    cout << "Valore: " << *x << *y << '\n'; 
  }
};

// specializzazione per puntatori
template <typename X, typename Y>
struct stampante<X*,Y> {
  void stampa(X* x, Y y) {
    cout << "Valore: " << *x << y << '\n'; 
  }
};

// specializzazione per puntatori
template <typename X, typename Y>
struct stampante<X,Y*> {
  void stampa(X x, Y* y) {
    cout << "Valore: " << x << *y << '\n'; 
  }
};


// specializzazione totale
template <>
struct stampante<bool, bool> {
  void stampa(bool x, bool y) {
    cout << "Valore: " << (x ? "vero" : "falso") 
                       << (y ? "vero" : "falso")<< '\n'; 
  }
};

// specializzazione parziale
template <typename X>
struct stampante<X,int> {
  void stampa(X x, int y) {
    cout << "Valore: " << x  << y << '\n'; 
  }
};


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

  int i{5};
  double d{3.14};
  stampaTipo<int>(i);
  stampaTipo<double>(d);
  stampaTipo(i);
  stampaValore(i);
  stampaValore(&d);

}