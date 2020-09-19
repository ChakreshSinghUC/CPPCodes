//https://leetcode.com/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int c[cost.size()];
        c[0] = cost[0];
        c[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            c[i] = cost[i] + min(c[i - 1], c[i - 2]);
        }
        return min(c[cost.size() - 1], c[cost.size() - 2]);
    }
};
int main()
{
    Solution obj;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << obj.minCostClimbingStairs(cost);
}