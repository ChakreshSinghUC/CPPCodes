#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> countBits(int num)
    {
        vector<int> ret(num + 1);
        ret[0] = 0;
        ret[1] = 1;
        ret[2] = 1;

        if (num > 2)
        {
            for (int i = 3; i <= num; i++)
                (i % 2 == 0) ? ret[i] = ret[i / 2] : ret[i] = ret[i - 1] + 1;
        }
        return ret;
    }
};
int main()
{
    Solution obj;
    int num = 5;
    vector<int> r = obj.countBits(5);
    for (auto i : r)
        cout << i << " ";
}