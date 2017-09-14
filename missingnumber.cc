#include <iostream>
using namespace std;
int main() {
  int A[] = {1, 2, 3, 5, 6, 7, 8};
  int size = sizeof(A) / sizeof(A[0]);
  int sum = 0;

  for (int i = 0; i < size; i++)
    sum += A[i];

  cout << ((size + 1) * (size + 2) / 2) - sum << endl;
}