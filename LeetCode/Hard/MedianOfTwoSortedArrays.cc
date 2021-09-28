// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nums;
        for (int i : nums1)
            nums.push_back(i);
        for (int i : nums2)
            nums.push_back(i);
        sort(nums.begin(), nums.end());

        double median = 0;
        if (nums.size() % 2 != 0)
            median = nums[nums.size() / 2];
        else
        {
            // cout<<nums[nums.size() / 2 - 1]<<"\t"<<nums[nums.size()/ + 2]<<endl;
            median = (nums[nums.size() / 2 - 1] + nums[nums.size()/ + 2]) / 2.0;
        }
        return median;
    }
};
int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    Solution obj;
    cout << obj.findMedianSortedArrays(nums1, nums2);
}