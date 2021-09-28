// https://leetcode.com/problems/russian-doll-envelopes/
// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other
// envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int ans = 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> LIS(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, LIS[i]);
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> envelopes{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution o;
    cout << o.maxEnvelopes(envelopes);
}