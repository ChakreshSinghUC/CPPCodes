#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int search(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << obj.search(nums, target);
}