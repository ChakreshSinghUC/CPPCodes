// https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ret;
    map<int, int> mymap;

    set<int> s;
    for (auto a : nums2)
      s.insert(a);

    int i = 0;

    for (auto a : nums1) {
      mymap.insert(pair<int, int>(a, i));
      i++;
    }

    for (auto a : s) {
      if (mymap.find(a) != mymap.end())
        ret.push_back(a);
    }

    return ret;
  }
};
int main() {
  vector<int> nums1{4, 9, 5};
  vector<int> nums2{9, 4, 9, 8, 4};
  Solution obj;
  vector<int> nums = obj.intersection(nums1, nums2);
  for (auto a : nums)
    cout << a << ", ";
}