#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int array_sum = 0;
    for (auto n : nums) {
      array_sum += n;
    }
    int left_sum = 0;
    int N = nums.size();
    for (int i = 0; i < N; i++) {
      if (left_sum == array_sum - left_sum - nums[i])
        return i;
      left_sum += nums[i];
    }
    return -1;
  }
};

int main() {
  vector<int> arr{1, 7, 3, 6, 5, 6};
  Solution o;
  cout << "Pivot Index: " << o.pivotIndex(arr);
}