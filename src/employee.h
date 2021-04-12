#include "abstractemployee.h"
#include <string>
#ifndef EMPLOYEE
#define EMPLOYEE
class Employee : public AbstractEmployee {
public:
  Employee(const std::string &name, const std::string &institute, int nr);
  // Employee() = default;
  ~Employee();
  const std::string &name() const override;
  const std::string &institute() const;
  int employeenr() const;
  virtual std::string classname() const;
  void name(const std::string& v);

protected:
  std::string m_name;
  std::string m_institute;
  int m_employeenr;
};
#endif // EMPLOYEE