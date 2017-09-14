#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string b = "11001";

  int size = b.size();
  int evenCount = 0, oddCount = 0;
  for (int i = 0; i < size; i++) {
    if (b[i] == '1' && i % 2 == 0)
      evenCount++;
    else if (b[i] == '1' && i % 2 != 0)
      oddCount++;
  }
  if ((evenCount - oddCount) % 3 == 0)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}