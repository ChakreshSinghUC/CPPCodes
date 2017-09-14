/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  
//     int result = 0;
//     int len = height.size();
//     if (len <= 2)
//       return 0;

//     int l = 0;
//     int w = 1;
//     bool leftwall = false;
//     int temp = 0;
//     while (l + w <= len - 1) {
//       while (height[l + w] < height[l] && l + w <= len - 1) {
//         temp += height[l + w];
//         w++;

//         if (l + w > len - 1 && w > 1) {
//           w = 1;
//           temp = 0;
//           l++;
//           leftwall = true;
//         }
//       }

//       if (leftwall) {
//         result += (max(height[l], height[l + w]) * w) - temp -
//                   (min(height[l], height[l + w]));
//       } else
//         result += (min(height[l], height[l + w]) * (w - 1)) - temp;
//       leftwall = false;
//       l = l + w;
//       w = 1;
//       temp = 0;
//     }

//     return result;
//   }
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
};
int main() {

  vector<int> height = {4, 2, 3}; //{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  Solution obj;
  cout << obj.trap(height);
}
