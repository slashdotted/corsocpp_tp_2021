#include <string>
#ifndef ABSTRACTEMPLOYEE
#define ABSTRACTEMPLOYEE
class AbstractEmployee {
public:
  virtual const std::string &name() const = 0;
};
#endif // ABSTRACTEMPLOYEE