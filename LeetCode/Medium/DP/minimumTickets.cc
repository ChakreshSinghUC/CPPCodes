// https://leetcode.com/problems/minimum-cost-for-tickets/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int n = days.size();
    int dp[n][n];
    fill_n(*dp, n * n, -1);

    for (int i = 0; i < days.size(); i++) {
      for (int j = i; j < days.size(); j++) {
          if(i == j)
            dp[i][j] = costs[0];
          else if (j - i < 7)
            dp[i][j] = min(costs[0]*(j-i+1), costs[1]);
          else if (j - i < 20)
             
      }
    }

   }
};