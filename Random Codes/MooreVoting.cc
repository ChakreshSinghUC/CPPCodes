#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int funct(int A[], int size) {
  map<int, int> m;
  map<int, int>::iterator itr;

  for (int i = 0; i < size; i++) {
    itr = m.find(A[i]);
    if (itr != m.end()) {
      itr->second++;
      if (itr->second > size / 2) {
        return (A[i]);
      }
    } else
      m.insert(pair<int, int>(A[i], 1));
  }
  return -100;
}
int main() {

  int A[] = {3, 1, 3, 3, 2};
  int size = sizeof(A) / sizeof(A[0]);
  int c = funct(A, size);
  if (c != -100)
    cout << c << endl;
  else
    cout << "No maximum" << endl;
}