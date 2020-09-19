#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int lastFilledEven = -2;
        int lastFilledOdd = -1;
        vector<int> B;
        for (auto a : A)
        {
            B.push_back(0);
        }
        //int i = 0;
        for (auto a : A)
        {
            if (a % 2 == 0)
            {
                B[lastFilledEven + 2] = a;
                lastFilledEven += 2;
            }
            else
            {
                B[lastFilledOdd + 2] = a;
                lastFilledOdd += 2;
            }
        }
        return B;
    }
};
int main()
{
    Solution obj;
    vector<int> A = {4, 2, 5, 7};
     vector<int> B = obj.sortArrayByParityII(A);
    for (auto b : B)
        cout << b << " ";
}