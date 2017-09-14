#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int A[1000];
    int size;

    cin >> size;

    for (int i = 0; i < size; i++)
      cin >> A[i];

    int count = 0;
    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < size; i++) {
      if (A[i] < 0)
        count++;
      max_ending_here = max_ending_here + A[i];
      if (max_ending_here < 0) {
        max_ending_here = 0;
      }
      if (max_so_far < max_ending_here) {
        max_so_far = max_ending_here;
      }
    }
    if (count == size) {
      sort(A, A + size);
      cout << A[size - 1] << endl;
    } else
      cout << max_so_far << endl;
  }
}
