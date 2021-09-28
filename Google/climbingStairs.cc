#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int climbStairs(int n)
    {
        vector<int> ways(n + 1, 0);
        if (n < 3)
            return n;

        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; i++)
            ways[i] = ways[i - 1] + ways[i - 2];
        return ways[n];
    }
};
int main()
{
    Solution obj;
    int n = 4;
    cout << obj.climbStairs(n);
}