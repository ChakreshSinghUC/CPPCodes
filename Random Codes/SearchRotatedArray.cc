// http://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0

#include <iostream>
using namespace std;
int find_pivot(int A[], int n) {
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (A[i + 1] > A[i])
      r++;
    else
      break;
  }
  return r;
}

int binary_search(int A[], int l, int r, int k) {
  int index = -1;
  int mid = (l + r) / 2;
  if (A[l] == k)
    return l;
  else if (A[r] == k)
    return r;
  else if (A[mid] == k)
    return mid;
  else if (k >= A[l] && k < A[mid])
    index = binary_search(A, l, mid, k);
  else if (k > A[mid] && k <= A[r])
    index = binary_search(A, mid, r, k);
  return index;
}
int main() {

  int t;
  cin >> t;
  while (t--) {
    int A[100005];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> A[i];

    int k;
    cin >> k;

    int pivot = find_pivot(A, n);

    if (k >= A[0] && k <= A[pivot])
      cout << binary_search(A, 0, pivot, k) << endl;
    else if (k >= A[pivot + 1] && k <= A[n])
      cout << binary_search(A, pivot + 1, n, k) << endl;
  }
}