// Given an array of integers nums,
//     calculate the pivot index of this array.

//     The pivot index is the index where the sum of all the numbers strictly to
//         the left of the index is equal to the sum of all the numbers strictly
//         to
//             the index's right.

//     If the index is on the left edge of the array,
//     then the left sum is 0 because there are no elements to the
//         left.This also applies to the right edge of the array
//             .

//     Return the leftmost pivot index.If no such index exists,
//     return -1.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  vector<int> left_to_right;
  int sum_so_far = 0;
  for (auto n : nums) {
    left_to_right.push_back(n + sum_so_far);
    sum_so_far += n;
  }
  int N = nums.size();
  sum_so_far = 0;

  stack<int> s;
  for (int i = N - 1; i >= 0; i--) {
    int curr_sum = nums[i] + sum_so_far;
    s.push(curr_sum);
    sum_so_far += curr_sum;
  }

  int idx = 0;
  while (!s.empty()) {
    if (left_to_right[idx] == s.top())
      cout << idx << endl;
  }
  cout << -1;
}