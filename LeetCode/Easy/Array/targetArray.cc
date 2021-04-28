// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> target;
        for (int i = 0; i < nums.size(); i++)
            target.insert(target.begin() + index[i], nums[i]);

        return target;
    }
};

int main()
{

    Solution obj;
    vector<int> nums{0, 1, 2, 3, 4};
    vector<int> index{0, 1, 2, 2, 1};

    vector<int> target = obj.createTargetArray(nums, index);
    for (auto a : target)
        cout << a << ", ";
}

}
