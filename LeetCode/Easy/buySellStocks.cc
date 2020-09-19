//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int BruteForce_maxProfit(vector<int> &prices)
    {

        int profit = 0;
        int k = 0;
        int N = prices.size();

        while (k < N - 1)
        {
            int buyAt = prices[k];
            for (int i = k + 1; i < N; i++)
            {
                profit = max((prices[i] - buyAt), profit);
            }
            k++;
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (auto price : prices)
            if (price < minprice)
                minprice = price;
            else if (price - minprice > maxprofit)
                maxprofit = price - minprice;

        return maxprofit;
    }
};
int main()
{
    vector<int> prices = {7, 6, 4, 3, 1};
    Solution o;
    cout << o.maxProfit(prices);
}