// https://leetcode.com/problems/largest-divisible-subset/

// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j])
// of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> answer;
        if (n == 0)
            return answer;

        vector<vector<int>> EDS{{}};

        for (int i = 0; i < n; i++)
        {
            vector<int> r;
            r.push_back(nums[i]);
            EDS.push_back(r);
        }
        for (int i = 0; i < n; ++i)
        {
            vector<int> maxSubset;
            for (int k = 0; k < i; ++k)
            {
                if (nums[i] % nums[k] == 0 && maxSubset.size() < EDS[k].size())
                    maxSubset.push_back(nums[k]);
            }
            for (auto a : maxSubset)
                EDS[i].push_back(a);
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i)
            if (ret.size() < EDS[i].size())
                ret = EDS[i];
        return ret;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution obj;
    vector<int> r = obj.largestDivisibleSubset(nums);
    for(int a: r)
        cout << a << " ";
}