// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sumZero(int n) {
      
    // Given an integer n, return any array containing n unique integers such
    // that they add up to 0.
    vector<int> ret;
     if(n == 2){
         ret.push_back(1);
         ret.push_back(-1);
         return ret;
     }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
      ret.push_back(i);
      sum += i;
    }
    ret.push_back(0 - sum);
    return ret;
  }
};
int main() {
  int n= 1;

  Solution obj;
  vector<int> r = obj.sumZero(n);
  for (auto a : r)
    cout << a << ", ";
}