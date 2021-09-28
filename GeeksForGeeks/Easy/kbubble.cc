#include <iostream>
using namespace std;
int main() {

  int A[] = {12, 0, 9, 123, -1, 34};
  int size = sizeof(A) / sizeof(A[0]);
  int k = 2;
  int t = k;
  while (t--) {
    for (int i = 0; i < size - 1; i++) {
      if (A[i] > A[i + 1])
        swap(A[i], A[i + 1]);
    }
  }
  for (int i = size - 1; i > size - 1 - k; i--)
    cout << A[i] << " ";
  cout << endl;
}