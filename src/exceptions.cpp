#include "exceptions.h"
#include <iostream>
#include <memory>

struct Data {
  Data(int i) : m_i{i} { std::cout << "Data::Data(" << i << ")\n"; }
  ~Data() { std::cout << "Data::~Data(" << m_i << ")\n"; }
  int m_i;
};

// https://en.cppreference.com/w/cpp/header/stdexcept

struct MiaEccezione {};

void foo() { throw 13; }

void bar() { throw "oops!"; }

void baz() { throw MiaEccezione{}; }

void esempio1() {
  try {
    baz();
  } catch (const MiaEccezione &e) {
    std::cout << "Problema!\n";
  }

  try {
    foo();
  } catch (const MiaEccezione &e) {
    std::cout << "Problema!\n";
  } catch (int v) {
    std::cout << "Problema!\n";
  } catch (const char *v) {
    std::cout << "Problema!\n";
    throw;        // rilancio l'eccezione
  } catch (...) { // catch generico
    std::cout << "Problema!\n";
  }
}

void esempio2() {
  // Data k{2};
  // auto k{new Data{2}};
  auto k{std::make_unique<Data>(2)};
  foo();
  // delete k;
}

void esempio3() noexcept { // con noexcept da esempio3 non possono "uscire"
                           // delle eccezioni
  Data d{3};
  // try {
  esempio2();
  // } catch(...) {
  //
  // }
}

void esempio4() {
  Data d{4};
  esempio3();
}

void exceptions_run() {
  try {
    esempio4();
  } catch (...) {
  }
}