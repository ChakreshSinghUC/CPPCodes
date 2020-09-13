#include<iostream>
#include<vector>

using namespace std;
int maxSubArray(vector<int> nums){
    int max_sum= 0;
    int steps = 0;
    for(int i = 0; i< nums.size()-1; i++){
        int current_sum = 0;
        for(int j = i; j<nums.size(); j++){
            steps++;
          current_sum += nums[j];
          max_sum=max(max_sum, current_sum);

        }
        
    }
    cout<<"Steps: "<<steps<<endl;
    return max_sum;
}

int maxSubArray_linear(vector<int> nums)
{
    int maxSum = 0;
    int current_sum = 0;
    int steps = 0;
    for(int i = 0; i<nums.size() ; i++)
    {
        maxSum=max(current_sum, maxSum);
        current_sum += nums[i];
        if(current_sum<0) current_sum = 0;
        steps++;
    }
    cout<<"Steps: "<<steps<<endl;
    return maxSum;
}
int main()
{
    vector<int> nums = {13, -3,-25, 20, -3,-16, -23, 18, 20, -7, 12, -5,-22,15, -4, 7};
    cout<<"Brute Force : "<< maxSubArray(nums)<<endl;
    cout<<"Linear : "<<maxSubArray_linear(nums);
}