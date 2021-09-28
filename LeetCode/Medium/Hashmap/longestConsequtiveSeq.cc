// https://leetcode.com/problems/longest-consecutive-sequence/
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for (int n : nums)
            num_set.insert(n);

        int longestStreak = 0;

        for (int n : num_set)
            {
            if (num_set.find(n - 1) == num_set.end()) {
                int current_num = n;
                int current_streak = 1;
                while (num_set.find(current_num + 1) != num_set.end())
                    {
                    current_num += 1;
                    current_streak += 1;
                    }
                longestStreak = max(longestStreak, current_streak);
                }
            }
        return longestStreak;
        }
    };

int main()
    {
    Solution obj;
    vector<int> nums{ 0,3,7,2,5,8,4,6,0,1 };
    for (auto a : nums)
        cout << a << ", ";
    obj.longestConsecutive(nums);
    }