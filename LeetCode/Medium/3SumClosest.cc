//https://leetcode.com/problems/3sum-closest/description/
/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.    
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int smaller_difference = 100000;
        int smaller_sum;
        int l, r;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int sum;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else if (sum == target)
                    return sum;
                if (abs(target - sum) < smaller_difference)
                {
                    smaller_difference = abs(target - sum);
                    smaller_sum = sum;
                }
            }
        }
        return smaller_sum;
    }
};
int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution obj;
    cout << obj.threeSumClosest(nums, target) << endl;
}