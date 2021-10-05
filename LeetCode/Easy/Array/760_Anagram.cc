// https://leetcode.com/problems/find-anagram-mappings/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    map<int, int> mymap;
    vector<int> P;

    for (int i = 0; i < B.size(); i++)
      mymap.insert(pair<int, int>(B[i], i));

    for (int i = 0; i < A.size(); i++)
      P.push_back(mymap[A[i]]);

    return P;
  }
};

int main() {
  vector<int> A{12, 28, 46, 32, 50};
  vector<int> B{50, 12, 32, 46, 28};
  Solution o;
  vector<int> p = o.anagramMappings(A, B);
  for (int a : p)
    cout << a << "\t";
}