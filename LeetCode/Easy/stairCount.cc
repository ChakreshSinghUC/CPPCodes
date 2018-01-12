//https://leetcode.com/problems/min-cost-climbing-stairs/description/
/**On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:

    cost will have a length in the range [2, 1000].
    Every cost[i] will be an integer in the range [0, 999].
**/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int steps = 0;
        int total = 0;
        int i = 0;
        if (cost.size() == 0)
            return 0;
        if (cost.size() == 1)
            return cost[0];

        while (i < cost.size())
        {
            (cost[i] < cost[i + 1]) ? steps = 0 : steps = 1;
            i += steps;
            total += cost[i];
            i++;
        }
        int total1 = cost[1];
        i = 2;
        while (i < cost.size())
        {
            (cost[i] < cost[i + 1]) ? steps = 0 : steps = 1;
            i += steps;
            // cout << i << endl;
            total1 += cost[i];
            i++;
        }
        // cout << total << "\t" << total1 << endl;
        if (total > total1)
            total = total1;
        return total;
    }
};
int main()
{
    Solution obj;
    vector<int> v = {0, 0, 0, 1};
    cout << obj.minCostClimbingStairs(v);
}