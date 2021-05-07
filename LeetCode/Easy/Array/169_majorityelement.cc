// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
     
    int m = nums.size() / 2;
    map<int, int> mymap;

    for (auto n : nums) 
      mymap[n]++;
    

    int _max = INT_MIN;
    int t; 
    for (auto a: mymap) {
      if (_max <a.second) {
        t = a.first;
        _max = a.second;
      } 
    }
      return t;
  }
};

int main() {

  vector<int> nums{-1,1,1,1,2,1};
  Solution obj;
  cout << obj.majorityElement(nums);
}