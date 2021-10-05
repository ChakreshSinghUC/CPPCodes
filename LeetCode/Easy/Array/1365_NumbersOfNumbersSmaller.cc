// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ret(nums.size(), 0);
        if (nums.empty())
            return ret;

        int i = 0;

        while (i < nums.size())
        {
            for (auto a : nums)
            {
                if (a < nums[i])
                    ret[i]++;
            }

            i++;
        }

        return ret;
    }
};

int main()
{
    vector<int> nums{8, 1, 2, 2, 3};
    Solution obj;
    vector<int> r = obj.smallerNumbersThanCurrent(nums);
    for (auto a : r)
        cout << a;
}