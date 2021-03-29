#include "virtualdestructor.h"
#include <iostream>
using namespace std;

class Base {
public:
  ~Base() { cout << "Destroying Base" << endl; }
};

class Derived : public Base {
public:
  Derived() : m_intptr{new int} {};
  ~Derived() {
    cout << "Destroying Derived" << endl;
    delete m_intptr;
  }

private:
  int *m_intptr;
};

class Manager {
public:
  Manager() : m_resource{nullptr} {};
  ~Manager() { delete m_resource; }
  void resource(Base *r) {
    delete m_resource; // delete resource through a pointer to Base
    m_resource = r;
  }

private:
  Base *m_resource;
};

void virtualdestructor_run() {
  Manager g;
  Derived *pd = new Derived();
  g.resource(pd);
}