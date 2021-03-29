#include "employee.h"
#include <string>
#ifndef LECTURER
#define LECTURER

class Lecturer : public Employee {
public:
  Lecturer(const std::string &name, const std::string &institute, int nr,
           const std::string &studies, const std::string &course);
  ~Lecturer();
  const std::string &studies() const;
  const std::string &course() const;
  std::string classname() const override;

protected:
  std::string m_studies;
  std::string m_course;
};
#endif // LECTURER