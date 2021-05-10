#include <iostream>
#include "mylist.h"
#include <typeinfo>

using std::cout;

struct Somma {
  Somma(int d) : m_d{d} {}

  int apply(int x, int y) {
    return x+y+m_d;
  }

private:
  int m_d;
};

int main() {
  Somma s{4};
  cout << s.apply(5,3) << '\n';

}