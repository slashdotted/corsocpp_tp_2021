#include <iostream>
#include <string>
using namespace std;
void fun(int x) {
    x = 1;
}
int main() {
    int s = 0;
    fun(s);
    cout << s << endl;
}
