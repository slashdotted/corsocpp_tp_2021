#include "employee.h"
#include "lecturer.h"
#include "researcher.h"
#include <iostream>

using std::cout;

int main() {
  Employee e{"Enea", "ISEA", 6523};
  Researcher r{"Riccardo", "ISIN", 1234, "DS"};
  Lecturer l{"Luca", "ISIN", 4453, "CS", "3D"};

  cout << e.name() << ',' << e.classname() << '\n';
  cout << r.name() << ',' << r.classname() << '\n';
  cout << l.name() << ',' << l.classname() << '\n';
  cout << "---------------------------------------------\n";
  Employee *pr{&r};
  Employee &rl{l};
  cout << pr->name() << ',' << pr->classname() << '\n';
  cout << rl.name() << ',' << rl.classname() << '\n';
}