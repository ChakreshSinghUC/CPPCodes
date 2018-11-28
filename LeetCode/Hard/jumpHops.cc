#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int hop_count = 0;
        int N = nums.size();
        int max_so_far = INT_MIN;
        if (N < 2)
            return 0;
        int temp = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (max_so_far < nums[i] + i && i <= max_so_far)
            {
               // cout << i << endl;
                hop_count++;

                max_so_far = nums[i] + i;
                temp = max_so_far;
                if (max_so_far >= N - 1)
                    return hop_count;
            }
        }
        return hop_count;
    }
};
int main()
{
    Solution o;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << o.jump(nums);
}