// https://leetcode.com/problems/ugly-number-ii/

#include<iostream>
#include<vector>

using namespace std;
 
 
class Solution {
  public: 
   int nthUglyNumber(int n) {
       vector<int> nums(1690, 0);
        nums[0] = 1;
      int ugly, i2 = 0, i3 = 0, i5 = 0;

      for (int i = 1; i < 1690; ++i) {
        ugly = min(min(nums[i2] * 2, nums[i3] * 3), nums[i5] * 5);
        nums[i] = ugly;

        if (ugly == nums[i2] * 2)
          ++i2;
        if (ugly == nums[i3] * 3)
          ++i3;
        if (ugly == nums[i5] * 5)
          ++i5;
      }
    return nums[n - 1];
  }
};

int main() { 
    Solution obj;
  cout << obj.nthUglyNumber(10);
}