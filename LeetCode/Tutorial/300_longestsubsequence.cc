// https://leetcode.com/problems/longest-increasing-subsequence/
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        vector<int> LIS(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, LIS[i]);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution obj;
    cout << obj.lengthOfLIS(nums);
}