#include <iostream>
#include <vector>
using namespace std;

int main() {
  string A = "ab";
  int size = A.size();
  int n = 1;
  int p = 0;
  vector<string> B(n);
  for (int i = 0; i < size; i++) {
    if (n == 1)
      // output same string as answer;
      ;
    if (p < n) {
      cout << i;
      B[p].push_back(A[i]);
    } else if (p >= n && p <= 2 * (n - 1)) {
      cout << i;
      B[(n - 2) - (p - n)].push_back(A[i]);
    }
    if (p == 2 * (n - 1))
      p = 0;
    p++;
  }
  for (int i = 0; i < B.size(); i++) {
    for (int j = 0; j < B[i].size(); j++) {
      cout << B[i][j];
    }
  }
}