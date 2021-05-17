// https://leetcode.com/problems/delete-and-earn/

// Given an array nums of integers, you can perform operations on the array.

// In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal
// to nums[i] - 1 or nums[i] + 1.

// You start with 0 points. Return the maximum number of points you can earn by applying such operations.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> points(n, 0);
        int max_points = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) != 1)
                    points[i] += nums[j];
            }
            max_points = max(max_points, points[i]);
            cout << i << "\t" << max_points << endl;
        }

        return max_points;
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 2, 4, 5, 5, 5, 6};

    Solution o;
    cout << o.deleteAndEarn(nums);
}