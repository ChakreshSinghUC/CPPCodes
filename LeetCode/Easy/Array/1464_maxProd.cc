// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
//  Given the array of integers nums, you will choose two different indices i
//  and j of that array.
//   Return the maximum value of (nums[i]-1)*(nums[j]-1).

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxProduct__bad(vector<int> &nums) {
    int max_prod = INT_MIN;

    for (int i = 0; i < nums.size() - 1;
         i++) { // don't like the O(n^2) complexity
      for (int j = i + 1; j < nums.size(); j++)
        max_prod = max(max_prod, (nums[i] - 1) * (nums[j] - 1));
    }
    return max_prod;
  }
  int maxProduct(vector<int> &nums) {
    int max_prod = INT_MIN;
    sort(nums.begin(), nums.end());
    int size = nums.size();

    return (nums[size - 1] - 1) * (nums[size - 2] - 1);
  }
};

int main() {
  vector<int> nums{1, 5, 4, 5};
  Solution obj;

  cout << obj.maxProduct(nums);
}