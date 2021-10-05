// https://leetcode.com/problems/split-array-with-same-average/

// You are given an integer array nums.

// You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).

// Return true if it is possible to achieve that and false otherwise.

// Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.

#include<iostream>
#include<vector> 

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // 1073741824
        
        for (int i = 0; i < n; i++) {
                
                }
            }

        return false;
        }
    };
int main()
    {
    vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8 };
    Solution o;
    cout << o.splitArraySameAverage(nums);
    }