#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {

                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
        throw new invalid_argument("No two sum solution");

    }
};
int main()
{
    Solution obj;
    vector<int> nums = {3, 2, 2,4};
    int target = 4;
    vector<int> ans = obj.twoSum(nums, target);
    for (auto i : ans)
    {
        cout << i << "\t";
    }
}