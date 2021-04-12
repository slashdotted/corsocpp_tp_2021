#include "virtualdestructor.h"
#include <iostream>
using namespace std;

class Base {
public:
  virtual ~Base() { cout << "Destroying Base" << endl; }
};

class Derived : public Base {
public:
  Derived() : m_intptr{new int} {};
  ~Derived() override {
    cout << "Destroying Derived" << endl;
    delete m_intptr;
  }

private:
  int *m_intptr;
};

class Manager {
public:
  Manager() : m_resource{nullptr} {};
  ~Manager() { if (m_resource) delete m_resource; }
  void resource(Base *r) {
    if (m_resource) delete m_resource; // delete resource through a pointer to Base
    m_resource = r;
  }

  Manager(const Manager&) = delete;
  Manager& operator=(const Manager&) = delete;

private:
  Base *m_resource;
};

void virtualdestructor_run() {
  Manager g;
  // Manager h;
  // g = h;
  Derived *pd = new Derived();
  g.resource(pd);
}