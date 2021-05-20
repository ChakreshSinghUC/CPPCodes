#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {

    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> res;
    res.push_back(nums[0]);
    int last = nums[0];

    int idx = 0, max_len = INT_MIN;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % last == 0) {
          res.push_back(nums[i]);
          last = nums[i];
        }
      }
    }
    return res;
  }

  vector<int> largestDivisibleSubset__poor(vector<int> &nums) {

    sort(nums.begin(), nums.end());
    int n = nums.size();

    if (n < 2)
      return nums;
    if (n == 2) {
      if (nums[1] % nums[0] == 0)
        return nums;
      else {
        vector<int> r;
        r.push_back(nums[0]);
        return r;
      }
    }

    vector<vector<int> > res(n, vector<int>({}));

    for (int i = 0; i < n; i++)
      res[i].push_back(nums[i]);

    int idx = 0, max_len = INT_MIN;
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i; j++) {
        int ni = res[i].size(), nj = res[j].size();
        if (ni < nj + 1 && nj > 0) {

          if (nums[i] % res[j][nj - 1] == 0) {
            res[i].clear();
            res[i] = res[j];
            res[i].push_back(nums[i]);
            int l = res[i].size();
            if (max_len < l) {
              max_len = l;
              idx = i;
            }
          }
        }
      }
    }

    return res[idx];
  }
};

int main() {
  vector<int> nums{2, 3, 5, 7, 11, 13, 17, 19, 23, 31};
  Solution o;

  vector<int> r = o.largestDivisibleSubset(nums);
  for (auto a : r)
    cout << a << ", ";
}