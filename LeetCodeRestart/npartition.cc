#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), [](const int a, const int b) { return a > b; });
    int s = 0;
    for (int i = 1; i < nums.size(); i += 2)
       s+=nums[i];
    return s;
}
int main()
{
    vector<int> nums = {3, 2, 5, 10, 6, 7, 9, 2};
    cout << arrayPairSum(nums);
}