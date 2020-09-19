#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main() {
  int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
  int size = sizeof(A) / sizeof(A[0]);

  map<int, int> m;
  map<int, int>::iterator itr;

  for (int i = 0; i < size + 1; i++)
    m.insert(pair<int, int>(i + 1, -100));

  for (int i = 0; i < size; i++) {
    itr = m.find(A[i]);
    itr->second = A[i];
  }

  for (itr = m.begin(); itr != m.end(); ++itr) {
    if (itr->second == -100) {
      cout << itr->first << endl;
    }
  }
}
