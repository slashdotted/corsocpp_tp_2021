#include <iostream>
#include "mylist.h"
#include <typeinfo>
#include <functional>
#include <vector>
#include <algorithm>

using std::cout;

struct Somma {
  Somma(int d) : m_d{d} {}

  int apply(int x, int y) {
    return x+y+m_d;
  }

  int operator()(int x, int y) {
    return x+y+m_d;
  }

private:
  int m_d;
};

static int s_d;
int somma_apply(int x, int y) {
  return x+y +s_d;
}

void foo(std::function<int(int,int)> l) {
  cout<< "foo: " << l(5,7) << "\n";
}

std::function<int(int,int)> gen_lambda(int& u) {
  int s_d2{4};
  //int s_d3{9};
  return [s_d2, &u](int x, int y) {
      return x+y+s_d2+u;
  };
}

auto gen_lambda2(int& u) {
  int s_d2{4};
  //int s_d3{9};
  return [s_d2, &u](int x, int y) {
      return x+y+s_d2+u;
  };
}

int main() {
  Somma s{4};
  s_d = 4;
  cout << s.apply(5,3) << '\n';
  cout << somma_apply(5,3) << '\n';
  cout << s(5,3) << '\n';

  int s_d2{4};
  int s_d3{9};
  // std::function<int(int,int)>
  auto somma_lambda = [s_d2, &s_d3/*capture list*/](int x, int y) 
    /* -> int */ {
      return x+y+s_d2+s_d3;
  };

  auto somma_lambda_v = [=](int x, int y) {
      return x+y+s_d2+s_d3;
  };

  auto somma_lambda_r = [&](int x, int y) {
      return x+y+s_d2+s_d3;
  };

  auto somma_lambda_vr = [=,&s_d2](int x, int y) {
      return x+y+s_d2+s_d3;
  };

  auto somma_lambda_rv = [&, s_d2](int x, int y) {
      return x+y+s_d2+s_d3;
  };

  cout << "Lambda " << somma_lambda(5,3) << '\n';
  s_d2=9;
  s_d3=4;
  cout << "Lambda " << somma_lambda(5,3) << '\n';

  foo(somma_lambda);
  
  auto l{gen_lambda(s_d3)};

  cout << l(5,3) << '\n';

  std::vector<int> vec{1,2,3,4,5,6};

  for(const auto& v : vec) {
    cout << v << '\n';
  }

  std::for_each(vec.begin(), vec.end(), [] (const auto& v) {
    cout << v << '\n';
  });

  std::for_each(vec.begin()+1, vec.begin()+3, [] (const auto& v) {
    cout << v << '\n';
  });

  std::for_each(vec.rbegin(), vec.rend(), [] (const auto& v) {
    cout << v << '\n';
  });

  




}