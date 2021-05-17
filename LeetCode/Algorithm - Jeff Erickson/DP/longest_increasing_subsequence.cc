// Time Complexity: O(n^2)
// LeetCode Reference: https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        nums.insert(nums.begin(), INT_MIN); //add a sentinel

        int n = nums.size();
        // LIS(i, j) is the length of the longest increasing subsequence from j to n after prefixing it with nums[i].
        vector<vector<int>> LIS(n + 1, vector<int>(n + 1, 0));

        for (int j = n; j >= 0; j--)
        {
            for (int i = 0; i <= j - 1; i++)
            {
                // if(j>n)
                //     LIS[i][j] = 0; -- not needed as the LIS matrix is already initialized with zeroes.
                if (nums[i] < nums[j])
                    LIS[i][j] = max(1 + LIS[j][j + 1], LIS[i][j + 1]); //take j-th num or skip it
                else
                    LIS[i][j] = LIS[i][j + 1]; // if j-th num is smaller than i-th num, skip the j-th num
            }
        }
        return LIS[0][1];
    }

    int LIS_secondAttempt(vector<int> &nums)
    {

        // Space complexity: O(n)
        // LIS[i] is the length of the longest increasing subsequence starting with A[i]
        nums.insert(nums.begin(), INT_MIN); //add a sentinel
        int n = nums.size();
        vector<int> LIS(n + 1, 0);

        for (int i = n; i >= 0; i--)
        {
            LIS[i] = 1;
            for (int j = i + 1; j <= n; j++)
            {
                if (nums[j] > nums[i] && LIS[i] < 1 + LIS[j])
                    LIS[i] = 1 + LIS[j];
            }
        }
        return LIS[0] - 1;
    }
};

int main()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18, 9, 1000};
    Solution o;
    cout << "The length of longest subsequence in the given array is: " << o.lengthOfLIS(nums) << endl;
    cout << "The length of longest subsequence in the given array is (second attempt): " << o.LIS_secondAttempt(nums);
}