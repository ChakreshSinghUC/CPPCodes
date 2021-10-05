// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int xorSum = 0;
        vector<int> arr;
        for (int i = 0; i < arr1.size(); i++)
            for (int j = 0; j < arr2.size(); j++)
                arr.push_back(arr1[i] & arr2[j]);
 
        // If the list only contains one element, then its XOR sum will be equal to this element.
        if (arr.size() == 1)
            return arr[0];

        int k = 1;
        xorSum = arr[0];
        while (k < arr.size())
        {
             xorSum ^= arr[k];
            k++;
        }

        return xorSum;
    }
};

int main()
// 0,1,2,0,2,1

{
    vector<int> arr1{12};
    vector<int> arr2{4};
    Solution obj;

    cout << obj.getXORSum(arr1, arr2);
 
}