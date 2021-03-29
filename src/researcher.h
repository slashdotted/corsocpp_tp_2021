#include <string>

class Researcher {
public:
  Researcher(const std::string &name, const std::string &institute, int nr,
             const std::string &researcharea);
  ~Researcher();
  const std::string &researcharea() const;
  std::string classname() const;

protected:
  std::string m_researcharea;
};