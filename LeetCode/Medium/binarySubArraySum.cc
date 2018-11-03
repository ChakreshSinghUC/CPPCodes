
//https://leetcode.com/problems/binary-subarrays-with-sum/
// The 4 subarrays are bolded below:
// 1,0, 1, 0----
// 1, 0, 1-----
// --0, 1, 0, 1
// -----1, 0, 1

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int count = 0;
        int l = 0;
        int sum = 0;
        bool flag = false;
        int index = 0;
        while (index < A.size() || (index == A.size() - 1 && flag))
        {
            if (!flag)
                sum += A[index];
            if (sum == S)
            {
                count++;
                index++;
                int m = 0;
                int n = 0;
                if (A[l] == 0 && A[index] == 0)
                {
                    while (A[l] == 1 && l < A.size())
                    {
                        l++;
                        m++;
                    }
                    while (A[index] == 1 && index < A.size())
                    {
                        index++;
                        n++;
                    }
                    count = count + (m * n);
                }
            }
            if (sum < S)
            {
                index++;
                flag = false;
            }
        }
        return count;
    }
};
int main()
{
    vector<int> A = {1, 0, 1, 0, 1};
    int S = 2;
    Solution obj;
    cout << obj.numSubarraysWithSum(A, S);
}