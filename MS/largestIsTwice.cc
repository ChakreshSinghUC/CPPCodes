// Largest Number At Least Twice of Others
// https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/

// You are given an integer array nums where the largest integer is unique
//     .

//     Determine whether the largest element in the array is at least twice
//         as much as every other number in the array.If it is,
//     return the index of the largest element, or return -1 otherwise.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int dominantIndex(vector<int> &nums) {
      int largest_num = INT_MIN;
      int largest_index = -1;
      for (int i = 0; i < (int)nums.size(); i++)
      {
        if (largest_num < nums[i]) {
          largest_num = nums[i];
          largest_index = i;
        }
      }


      for (int i = 0; i<(int) nums.size(); i++)
      {
        
          if (i != largest_index && largest_num < 2 * nums[i] && nums[i] != 0)
          {
            cout << i << "\t" << largest_index << "\t" << nums[i] << endl;
            return -1;
            }
      }
      return largest_index;
  }
};

int main() { vector<int> arr{0,0,1,2};
    Solution o;
    cout << o.dominantIndex(arr);
}