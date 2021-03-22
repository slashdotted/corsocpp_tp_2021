#include "smartpointers_shared.h"
#include <iostream>
#include <memory>

struct Data {
  Data(int i) : m_i{i} { std::cout << "Data::Data(" << i << ")\n"; }
  ~Data() { std::cout << "Data::~Data(" << m_i << ")\n"; }
  int m_i;
};

void foo(std::shared_ptr<Data> &k) {
  std::shared_ptr<Data> temp{k};
  std::cout << "Utilizzatori: " << k.use_count() << '\n';
}

void bar(std::shared_ptr<Data> k) {
  std::cout << "Utilizzatori: " << k.use_count() << '\n';
}

void smartpointers_shared_run() {
  std::shared_ptr<Data> p{new Data{1}};
  auto p2{std::make_shared<Data>(2)};
  std::cout << "Utilizzatori di p: " << p.use_count() << '\n';
  std::shared_ptr<Data> p3 = p;
  std::cout << "Utilizzatori: " << p.use_count() << '\n';
  foo(p);
  std::cout << "Utilizzatori: " << p.use_count() << '\n';
  bar(p);
  std::cout << "Utilizzatori: " << p.use_count() << '\n';
  std::cout << "p =" << p.get() << '\n';
  std::cout << "p3=" << p3.get() << '\n';
}
