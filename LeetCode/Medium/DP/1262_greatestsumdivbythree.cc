// https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Given an array nums of integers, we need to find the maximum possible sum of
// elements of the array such that it is divisible by three.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    // sums[i] = max sum divisible by that includes i-th element of nums
    vector<int> sums(n, 0);
    sort(nums.begin(), nums.end());
    sums[0] = (nums[0] % 3) ? 0 : nums[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (sums[i] + sums[j] % 3 == 0)
          sums[i] = max(sums[i], sums[i] + sums[j]);
      }
    }

    int m = INT_MIN;
    for (auto a : sums)
      m = max(m, a);
    return m;
  }
};

int main() {
  vector<int> nums{3, 6, 5, 1, 8};
  Solution o;
  cout << o.maxSumDivThree(nums);
}