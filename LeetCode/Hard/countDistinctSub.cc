#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int distinctSubseqII(string S)
    {
        long MOD = 1e9 + 7;
        int N = S.length();
        int dp[N + 1];
        dp[0] = 1;
        int last[26];
        for (int i = 0; i < 26; i++)
            last[i] = -1;
        for (int i = 0; i < N; i++)
        {
            int x = S[i] - 'a';
            dp[i + 1] = (dp[i] * 2) % MOD;
            if (last[x] >= 0)
            {
                dp[i + 1] -= dp[last[x]];
            }
            dp[i + 1] %= MOD;
            last[x] = i;
        }
        dp[N]--;
        if (dp[N] < 0)
            dp[N] += MOD;
        return dp[N];
    }
};

int main()
{
    string S = "aaax";
    Solution obj;
    cout << obj.distinctSubseqII(S);
}