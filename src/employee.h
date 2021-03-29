#include <string>

class Employee {
public:
  Employee(const std::string &name, const std::string &institute, int nr);
  ~Employee();
  const std::string &name() const;
  const std::string &institute() const;
  int employeenr() const;
  std::string classname() const;

protected:
  std::string m_name;
  std::string m_institute;
  int m_employeenr;
};