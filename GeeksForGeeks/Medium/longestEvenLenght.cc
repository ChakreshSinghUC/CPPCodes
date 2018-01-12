#include <iostream>
#include <string>
using namespace std;
bool check(string str, int i, int j) {

  int lsum = 0;
  int rsum = 0;

  for (int k = i; k <= j; k++) {
    if (k <= (i + j) / 2)
      lsum += 48 - str[k];
    else
      rsum += 48 - str[k];
  }
  return lsum == rsum ? true : false;
}
int main() {
  string str;
  str = "000000";
  int size = str.size();

  int M[size][size];

  int c = 0;

  int len = 0;

  cout << size << endl;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((j - i + 1) % 2 == 0 && i != j) {
        if (check(str, i, j) && ((j - i + 1) > len))
          len = j - i + 1;
      }
    }
  }
  cout << "Answer: " << len << endl;
  return 0;
}