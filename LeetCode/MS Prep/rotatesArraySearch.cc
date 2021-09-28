// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<vector>
#include<iostream>
#include<map> 

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> hm;
        for (int i = 0; i<nums.size(); i++)
            {
                hm.insert(pair<int, int>(nums[i], i));
            }

        if (hm.find(target) != hm.end())
            return hm.find(target)->second;
            return -1;
        }
    };

int main()
    {
    vector<int> nums{ 4,5,6,7,0,1,2 };
    int target = 3;
    Solution o;
    cout << o.search(nums, target);
    }