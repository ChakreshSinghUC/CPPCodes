// https://leetcode.com/problems/three-equal-parts/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    int ones_count(vector<int> A)
    {
        int count = 0;
        for (auto c : A)
        {
            if (c == 1)
                count++;
        }
        return count;
    }
    vector<int> threeEqualParts(vector<int> &A)
    {
        vector<int> P;
        int count = ones_count(A);
        unsigned long num = 0;
        for (auto a : A)
        {
            num = (10 * num) + a;
        }

        int part = 0;
        if (count % 3 != 0)
        {
            P.emplace_back(-1);
            P.emplace_back(-1);
            return P;
        }
        part = count / 3;
        int val = 0;
        unsigned long temp = num;
        int ones = 0;
        while (ones < part)
        {
            if (temp % 10 == 1)
                ones++;
            val = (val * 10) + (temp % 10);
            temp /= 10;
        }
        int t = 0;
        while (val)
        {
            t = (t * 10) + val % 10;
            val /= 10;
        }
        cout << t;
        return P;
    }
};
int main()
{
    vector<int> A = {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1};
    Solution obj;
    vector<int> O = obj.threeEqualParts(A);
    for (auto o : O)
        cout << o << " ";
}