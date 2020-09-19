#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    }
};*/

class Solution
{
  public:
    vector<int> twosums(vector<int> nums, int target, int index)
    {
        int len = nums.size();
        vector<int> res;
        vector<int> n;
        
       for(int i = index+1; i<nums.size(); i++)
        {
            n.push_back(res[i]);
        }
        
        map<int, int> hmap;
        hmap.clear();
        
        for (int i = 0; i < n.size(); i++)
        {
            hmap[n[i]] = i;
        }
        for (int i = 0; i < n.size()-1; i++)
        {
            if (hmap.find((target - n[i])) != hmap.end())
            {
                if (i < hmap[target - n[i]])
                {
                    res.push_back(n[i]);
                    res.push_back(n[hmap[target - n[i]]]);
                    return res;
                }
                if (i > hmap[target - n[i]])
                {
                    res.push_back(hmap[target - n[i]] + 1);
                    res.push_back(i + 1);
                    return res;
                }
            }
        }
    }

    vector<vector<int>> fourSum (vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<vector<int>> finalOutput;
        vector<int> v;
        for (int i = 0; i < len - 3; i++)
        {
            for (int j = i + 1; j < len - 2; j++)
            {
                v.clear();
                v = twosums(nums, target - nums[i] - nums[j], j);
                if (!v.empty())
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);

                    sort(v.begin(), v.end());
                    finalOutput.push_back(v);
                }
            }
        }
        
        sort(finalOutput.begin(), finalOutput.end());
        finalOutput.erase(unique(finalOutput.begin(), finalOutput.end()), finalOutput.end());
        return finalOutput;
    }
};


int main()
{
    Solution obj;
    vector<int> nums = {0,0,0,1};
    int target = 1;
    vector<vector<int>> ret = obj.fourSum (nums, target);
    for (auto i : ret)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
   //cout <<ret.size();
}