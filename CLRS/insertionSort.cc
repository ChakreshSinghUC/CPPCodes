//Insertion Sort
//Page: 17-18

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &nums)
{
   for(int j = 1; j<nums.size(); j++)
   {
      int i = j-1;
      int key = nums[j];
      while(i>=0 and nums[i]>key){
         nums[i+1]=nums[i];
         i--;
      }
      nums[i+1]=key;
   }
}
int main()
{
   cout<<"Insertion Sort Started!!!\n Input sequence: \n";
   vector<int> nums = {2,1,4,6,1,0,-9,9};
   for(int a : nums) 
      cout<<a<<", ";
   insertionSort(nums);

  cout<<"\n\nInsertion Sort Finished!!!\n Output sequence: \n";
    for(int a : nums) 
      cout<<a<<", ";
   return 1;
}

