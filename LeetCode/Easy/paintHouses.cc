#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minCost(vector<vector<int>> &costs)
    {
        int N = costs.size();
        if (costs.size() == 0)
            return 0;
        for (int i = 1; i < costs.size(); i++)
        {
            costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][1], costs[i - 1][0]);
        }
        int n = costs.size() - 1;
        return min(min(costs[n][0], costs[n][1]), costs[n][2]);
    }
};

int main()
{
    vector<vector<int>> costs = {{5, 8, 6}, {19, 14, 13}, {7, 5, 12}, {14, 15, 17}, {3, 20, 10}};
    Solution obj;
    cout << obj.minCost(costs);
}