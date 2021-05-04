#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    vector<string> r;
    string s, e;

    if (nums.empty()) {
      if (lower == upper)
        r.push_back(to_string(lower));
      else
        r.push_back(to_string(lower) + "->" + to_string(upper));

      return r;
    }

    if (lower < nums[0]) {
      if (nums[0] - lower == 1)
        r.push_back(to_string(lower));
      else
        r.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
    }
    if (nums.size() == 1) {
      if (upper - nums[0] == 1)
        r.push_back(to_string(upper));
      if (upper - nums[0] > 1)
        r.push_back(to_string(nums[0] + 1) + "->" + to_string(upper));

      return r;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] - nums[i] != 1) {
        if (nums[i + 1] - nums[i] == 2)
          r.push_back(to_string(nums[i] + 1));
        else
          r.push_back(to_string(nums[i] + 1) + "->" +
                      to_string(nums[i + 1] - 1));
      }
    }
    if (upper > nums[nums.size() - 1]) {
      if (upper - nums[nums.size() - 1] == 1)
        r.push_back(to_string(upper));
      else
        r.push_back(to_string(nums[nums.size() - 1] + 1) + "->" +
                    to_string(upper));
    }
    return r;
  }
};

int main() {
  Solution obj;
  vector<int> nums{0, 1, 3, 50, 75};
  int lower = 0, upper = 99;
  vector<string> s = obj.findMissingRanges(nums, lower, upper);
  for (auto a : s)
    cout << a << ", ";
}