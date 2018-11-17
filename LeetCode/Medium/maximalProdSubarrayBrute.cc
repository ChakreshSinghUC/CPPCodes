#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
  
    int maxProductBrute(vector<int> &nums)
    {
        int prod;
        int maxProd = INT_MIN;
        {
            for (int i = 0; i < nums.size(); i++)
            {
                prod = INT_MAX;
                for (int j = i; j < nums.size(); j++)
                {
                    (prod == INT_MAX) ? prod = nums[j] : prod *= nums[j];
                    maxProd = max(prod, maxProd);
                    //  cout << i << "\t" << j << " :: " << maxProd << endl;
                }
            }
        }
        return maxProd;
    }

    int maxProductRecommended(vector<int> &nums)
    {
        int n = nums.size(), ans = nums[0];
        for (int i = 1, imin = ans, imax = ans; i < n; i++)
        {
            if (nums[i] < 0)
                swap(imin, imax);
            // save the consecutive product consists of even number negative values
            imax = max(nums[i], nums[i] * imax);
            // save the consecutive product consists of odd number negative values
            imin = min(nums[i], nums[i] * imin);
            ans = max(ans, imax);
        }
        return ans;
    }
    int maxProductCopied(vector<int> &nums)
    {
        int prev = nums[0];
        int curr;
        for (int i = 1; i < nums.size(); i++)
        {
            curr = max(prev * nums[i], prev);
            prev = curr;
        }
        return curr;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {2, 3, -2, 4};
    cout << obj.maxProduct(nums);
}                                                            