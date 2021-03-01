#include <iostream>
#include <string>
using namespace std;
void fun(string* x) {
    x = new string{"hello world"};
}
int main() {
    string* s = new string{"hello moon"};
    fun(s);
    cout << s << endl;
    // we ignore the leak due to s
}
