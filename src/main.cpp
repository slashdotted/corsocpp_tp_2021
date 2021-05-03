#include <iostream>
#include "mylist.h"

using std::cout;

int main() {
  MyList ml{10};
  for (const auto& i : {0,1,2,3,4,5,6,7,8,9}) {
    ml[i] = i;
  }
  for (const auto& i : {0,1,2,3,4,5,6,7,8,9}) {
    cout << ml[i] << '\n';
  }

}