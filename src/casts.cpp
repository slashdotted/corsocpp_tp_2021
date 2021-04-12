#include "casts.h"
#include "lecturer.h"
#include "lecturerresearcher.h"
#include "researcher.h"
#include <cassert>
#include <iostream>

void static_cast_example() {
  Lecturer d{"John", "ISIN", 42, "Computer Science",
             "Languages and Frameworks"};
  // Object conversion
  Employee c = static_cast<Employee>(d);
  // Conversion of a reference/pointer
  Employee &rc = static_cast<Employee &>(d); // beware of virtual inheritance!!!
  Employee *pc;
  pc = static_cast<Employee *>(&d); // Ok
  // auto rd = static_cast<Lecturer*>(pc); // Non posso attraversare verso il basso la derivazione virtual

  // Errors / Limitations of static_cast
  Researcher *pr;
  LecturerResearcher *pdr;
  // pr = static_cast<Researcher*>(pc); // Error!
  pdr = static_cast<LecturerResearcher *>(&d);         // Undetected error!
  std::cout << pdr->researchpercentage() << std::endl; // Garbage!
}

void enum_class_cast() {
  enum class Test { A, B, C, D };
  enum class Test2 { A = 100, B, C, D };

  std::cout << static_cast<int>(Test::B) << std::endl;
  Test y{static_cast<Test>(3)};
  int z{static_cast<int>(y)};
  std::cout << z << std::endl;
  assert(y == Test::D);
  std::cout << static_cast<int>(Test2::B) << std::endl;
  Test2 y2{static_cast<Test2>(103)};
  int z2{static_cast<int>(y2)};
  std::cout << z2 << std::endl;
  assert(y2 == Test2::D);
}

void dynamic_cast_example() {
  Lecturer d{"John", "ISIN", 42, "Computer Science",
             "Languages and Frameworks"};

  // Cannot convert objects with dynamic_cast
  // Employee c = dynamic_cast<Employee>(d); // Error!

  // Conversion of a reference/pointer
  Employee &rc = dynamic_cast<Employee &>(d);
  Employee *pc;
  pc = dynamic_cast<Employee *>(&d); // Ok

  // Invalid cast (detected by dynamic_cast)
  Researcher *pr;
  LecturerResearcher *pdr;
  pr = dynamic_cast<Researcher *>(pc);          // Returns nullptr!
  pdr = dynamic_cast<LecturerResearcher *>(&d); // Returns nullptr!
  std::cout << pr << ", " << pdr << std::endl; 
  
  auto rpr = dynamic_cast<Researcher&>(d);          // throws
  auto rpdr = dynamic_cast<LecturerResearcher&>(d);   // throws       
}

bool instanceofLecturer(Employee *p) {
  Lecturer *v = dynamic_cast<Lecturer *>(p);
  return (v != nullptr);
}

void reinterpret_cast_example() {
  Lecturer d{"John", "ISIN", 42, "Computer Science",
             "Languages and Frameworks"};

  // Cannot convert an object
  // Employee c = reinterpret_cast<Employee>(d);

  // Casting a reference / pointer
  Employee &rc = reinterpret_cast<Employee &>(d);
  Employee *pc;
  pc = reinterpret_cast<Employee *>(&d); // Ok

  // Errors / Limitations of reinterpret_cast
  Researcher *pr;
  LecturerResearcher *pdr;
  pr = reinterpret_cast<Researcher *>(pc);             // Invalid cast
  pdr = reinterpret_cast<LecturerResearcher *>(&d);    // Invalid cast
  std::cout << pdr->researchpercentage() << std::endl; // Garbage!
}

class Base {
public:
  void foo() const {}
  void bar() {}
};

void const_cast_example() {
  const Base *b{new Base};
  b->foo(); // Ok
  // b->bar(); // Error! Not const!
  // Base* bc = static_cast<Base*>(b); // Not permitted
  // Base* bc = reintepret_cast<Base*>(b); // Not permitted
  // Base* bc = dynamic_cast<Base*>(b); // Not permitted
  Base *bc = const_cast<Base *>(b); // Ok
  bc->bar();                        // Ok
}

void casts_run() {
    //static_cast_example();
    //enum_class_cast();
    dynamic_cast_example();
    //reinterpret_cast_example();
    //const_cast_example();
}