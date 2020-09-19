#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/jump-game/
//https://leetcode.com/problems/jump-game-ii/
class Solution
{
  public:
    bool canJumpProb1(vector<int> &nums)
    {
        int furthest_reach_so_far = 0, last_index = nums.size() - 1;
        for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i)
            furthest_reach_so_far = max(furthest_reach_so_far, i + nums[i]);

        return furthest_reach_so_far >=
               last_index;
    }
    int canJumpProb2(vector<int> &nums)
    {
        int furthest_reach_so_far = 0, last_index = nums.size() - 1;
        int count_hops = 0;
        for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i)
        {
            if (furthest_reach_so_far < i + nums[i])
                count_hops++;
            furthest_reach_so_far = max(furthest_reach_so_far, i + nums[i]);
        }
        return count_hops;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << obj.canJumpProb2(nums);
}