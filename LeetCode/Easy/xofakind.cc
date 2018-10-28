#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
  public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        vector<int> counts;
        sort(deck.begin(), deck.end());
        int count = 1;
        int m = INT_MAX;
        for (int i = 0; i < deck.size(); i++)
        {
            if (deck[i] == deck[i + 1])
            {
                count++;
            }
            else
            {
                counts.push_back(count);
                m = min(count, m);
                count = 1;
            }
        }

        for (auto a : counts)
        {
            if (a % m != 0)
            {
               
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    vector<int> d = {1, 1, 1, 2, 2, 2, 3, 3};
    cout << obj.hasGroupsSizeX(d);
}