#include <bits/stdc++.h>

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        if (nums.size() <= 1) return true; 

        int k = 0;
        int count = 0;
        for (int i=1; i<nums.size(); i++){
            if(nums[k]<=nums[i]){
                count++;
                }
                k++;
            
        }

       return  (count>=nums.size()-2)?true:false; 
    }
};
using namespace std;
int main (){
    vector<int> nums= {4,1,3};
    Solution obj;
    obj.checkPossibility(nums);
}
