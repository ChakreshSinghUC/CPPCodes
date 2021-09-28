#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int numWays(int n, int k)
    {
        if (n == 0 || k == 0)
            return 0;
        if (n == 1)
            return k;
        int f[n];
        f[0] = k;
        f[1] = k * (k - 1) + f[0];
        for (int i = 2; i < n; i++)
            f[i] = (f[i - 2] * (k - 1)) + (f[i - 1] * (k - 1));
        return f[n - 1];
    }
};
int main()
{
    Solution obj;
    cout << obj.numWays(3, 2);
}