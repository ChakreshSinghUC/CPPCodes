#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n][n];
        // fill(dp[0], dp[0] + n * n, 0);

        int _max;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
            int k = 0;
            int _min = nums[i];

            while (i + k < n)
            {
                _min = min(nums[i + k], _min);
                if (k > 0)
                    dp[i][i + k] = (dp[i][i + k - 1] + nums[i + k]);
                else
                    dp[i][i] = nums[i];
                _max = max(_max, dp[i][i + k] * _min);
                k++;
            }
        }

        return _max % 1000000007;
    }
};

int main()
{
    Solution obj;
    vector<int> nums{1, 2, 3, 2};
    cout << obj.maxSumMinProduct(nums);
}