// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;

        int min_operations = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i] >= nums[i + 1])
            {
                min_operations = min_operations + abs(nums[i] - nums[i + 1]) + 1;
                nums[i + 1] = nums[i] + 1;
            }
        }

        //         for(auto a: nums)
        //             cout<<a<<" ";

        return min_operations;
    }
};
int main()
{
    Solution obj;
    vector<int> nums{1, 1, 1};
    cout << obj.minOperations(nums);
}