#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int minFlipsMonoIncr(string S)
    {
        int P[S.length() + 1] = {0};
        int N = S.length();
        for (int i = 0; i < N; ++i)
            P[i + 1] = P[i] + (S[i] == '1' ? 1 : 0);

        int ans = INT_MAX;
        for (int j = 0; j <= N; ++j)
        {
            ans =min(ans, P[j] + N - j - (P[N] - P[j]));
        }
        return ans;
    }
};
int main()
{
    string S = "010110";
    Solution o;
    cout << o.minFlipsMonoIncr(S);
}