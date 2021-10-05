#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> points = nums;
    int max_point = INT_MIN;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (abs(nums[i] - nums[j]) != 1)
          points[i] = max(points[i], nums[i] + points[j]);

        max_point = max(max_point, points[i]);
      }
    }
    return max_point;
  }
};

int main() {
  vector<int> nums{8,10,4,9,1,3,5,9,4,10};
  Solution o;
  cout << o.deleteAndEarn(nums);
}