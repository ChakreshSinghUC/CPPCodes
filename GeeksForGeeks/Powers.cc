#include <iostream>
using namespace std;
double powers(double x, int p) {
  double r = 1;
  while (p > 0) {
    if (p % 2 == 0) {
      x = x * x;
      p = p / 2;
    } else {
      r = r * x;
      p = p - 1;
    }
  }
  return r;
}
int main() {
  double x = 5.5;
  int p = 3;
  cout <<x<<" raised to the power of "<<p<<"="<< powers(x, p);
  return 1;
}