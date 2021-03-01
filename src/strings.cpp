#include "strings.h"
#include <iostream>
#include <string>

void strings_run() {
  std::string messaggio{"Ciao mondo"};
  std::string msg;
  std::cout << "Stringa:" << msg << '\n';
  msg = "Ciao mondo";
  std::cout << "Stringa:" << msg << '\n';
  msg += "!";
  std::cout << "Stringa:" << msg << '\n';
  std::string msg2;
  msg2 = "Hello";
  msg = msg + msg2;
  std::cout << "Stringa:" << msg << '\n';
  std::cout << msg[0] << msg[1] << '\n';
  msg.insert(4, "---");
  std::cout << "La stringa è:" << msg << '\n';
  std::string a;
  std::string b;
  a = "a";
  b = "à";
  std::cout << "a=" << a << ", b=" << b << '\n';
  std::cout << "a=" << a.size() << ", b=" << b.size() << '\n';
  std::cout << "b[0]=" << b[0] << ", b[1]=" << b[1] << '\n';
}