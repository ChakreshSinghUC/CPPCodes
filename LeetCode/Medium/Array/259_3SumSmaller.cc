
// https://leetcode.com/problems/3sum-smaller/
// find the number of index triplets i, j, k with 0 <= i < j < k < n
// that satisfy the condition nums[i] + nums[j] + nums[k] < target.

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int twoSumSmaller(vector<int> n, int t) {
    int new_target;
    int count = 0;
    // map<int, int> mymap;
    // for (int i = 0; i < n.size(); i++)
    //     mymap.insert(pair<int, int>(i, n[i]));

    for (int i = 0; i < n.size() - 1; i++) {
      new_target = t - n[i];
      for (int j = i + 1; j < n.size(); j++)
        if (n[j] < new_target)
          count++;
    }
    return count;
  }
  int threeSumSmaller(vector<int> &nums, int target) {
    int count = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
      vector<int> v2(nums.begin() + i + 1, nums.end());
      count += twoSumSmaller(v2, target - nums[i]);
    }
    return count;
  }
};

int main() {
  vector<int> vec{-2, 0, 1, 3};
  int target = 2;

  Solution obj;
  cout << obj.threeSumSmaller(vec, target);
}
