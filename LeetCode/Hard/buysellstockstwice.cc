#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int max_total_profit = 0;
        vector<int> first_buy_sell_profit(prices.size(), 0);
        int min_price_so_far = INT_MAX;

        for (int i = 0; i < prices.size(); ++i)
        {
            min_price_so_far = min(min_price_so_far, prices[i]);
            max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
            first_buy_sell_profit[i] = max_total_profit;
        }
        int max_price_so_far = INT_MIN;
        for (int i = prices.size() - 1; i > 0; --i)
        {
            max_price_so_far = max(max_price_so_far, prices[i]);
            max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profit[i - 1]);
        }
        return max_total_profit;
    }
};
int main()
{

    Solution o;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << o.maxProfit(prices);
}