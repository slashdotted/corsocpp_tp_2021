#include "functions.h"

// int f() { return 13; }

int f(int x = 0) { return x + 13; }

double f(double x) { return x + 13.5; }

// Overload non valido
/*int f(double x) {
    return x+13.5;
}*/

int somma(int x, int y = 0, int z = 0, int j = 0) { return x + y + z + j; }

void g(int, double) {}
// void g(double, int) {}
// void g(int, int) {}
void g(double, double) {}

void functions_run() {
  somma(1); // somma(1,0,0,0);
  somma(1, 5);
  somma(3, 5, 6);
  somma(3, 5, 6, 7);
  g(7, 3.14);
  g(2.6, 8);
  g(7, double(3));
  g(3.14, int(2.7));
  g(int(3.14), 2.7);
  g(3.14, 2.7);
  g(7, 3);
}