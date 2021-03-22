#include "smartpointers_unique.h"
#include <iostream>
#include <memory>
#include <vector>

struct Data {
  Data(int i) : m_i{i} { std::cout << "Data::Data(" << i << ")\n"; }
  ~Data() { std::cout << "Data::~Data(" << m_i << ")\n"; }
  int m_i;
};

void foo(std::unique_ptr<Data> &k) {
  // std::unique_ptr<Data> temp{k}; // non posso copiare
}

void bar(std::unique_ptr<Data> k) {}

void baz(std::unique_ptr<Data> &&v) {
  std::unique_ptr<Data> temp{std::move(v)};
  // temp è il nuovo proprietario
}

std::unique_ptr<Data> buz() {
  auto k{std::make_unique<Data>(3)};
  return k;
}

void boz() { auto k{std::make_unique<Data>(3)}; }

struct Factory {
  Data *crea() { return new Data{7}; }
};

struct Factory2 {
  Data *crea() {
    auto p{new Data{7}};
    instances.push_back(p);
    return p;
  }

  ~Factory2() {
    for (auto &i : instances) {
      delete i;
    }
  }

  Factory2(const Factory2 &) = delete;
  Factory2 &operator=(const Factory2 &) = delete;

  std::vector<Data *> instances;
};

struct Factory3 {
  std::unique_ptr<Data> crea() { return std::make_unique<Data>(7); }
};

void smartpointers_unique_run() {
  std::cout << "smartpointers_run inizio\n";
  {
    std::unique_ptr<Data> p{new Data{1}};
    auto p2{std::make_unique<Data>(2)};
    auto p4{buz()};
    buz();
    foo(p);
    foo(p2);
    std::cout << "Puntatore p=" << p.get() << '\n';
    baz(std::move(p));
    // da qui, p non è più il proprietario dell'allocazione
    std::cout << "Puntatore p=" << p.get() << '\n';

    // std::unique_ptr<Data> p3 = p2; // non posso copiare
    // bar(p); // non posso copiare
    // bar(p2); // non posso copiare

    std::vector<std::unique_ptr<Data>> dati;
    dati.push_back(std::make_unique<Data>(6));
    dati.push_back(std::make_unique<Data>(7));
    dati.push_back(std::make_unique<Data>(8));
    dati.push_back(std::make_unique<Data>(9));
    dati.clear();
  }
  std::cout << "smartpointers_run fine\n";
}