// https://leetcode.com/problems/third-maximum-number/
// Given integer array nums, return the third maximum number in this array. If
// the third maximum does not exist, return the maximum number.
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:

  int thirdMax(vector<int> &nums) {
    set<int> s;
    for (auto a : nums) {
      s.insert(a);
    }

    int k = 0;
    int N = s.size();

    int n;
    if (s.size() < 3)
      n = 1;
    else
      n = 3;
    for (auto a : s) {

      if (k == N - n)
        return a;
      k++;
    }
    return 1;
  }
};
int main() {
  vector<int> nums{2, 1};
  Solution obj;
  cout << obj.thirdMax(nums);
}