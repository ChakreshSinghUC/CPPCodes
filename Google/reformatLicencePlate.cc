// https://leetcode.com/explore/interview/card/google/67/sql-2/472/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    void to_upper(string &P)
    {
        int k = 0;
        while (k < P.length())
        {
            if (P[k] >= 97 && P[k] <= 122)
            {
                P[k] = toupper(P[k]);
            }
            k++;
        }
    }
    string licenseKeyFormatting(string S, int K)
    {
        string P;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] != '-')
            {
                P = P + S[i];
            }
        }
        to_upper(P);

        int k = 0;
        string outPut;
        reverse(P.begin(), P.end());
        while (k < P.length())
        {
            outPut += P[k];
            if ((k + 1) % K == 0 && k != P.length() - 1)
                outPut += '-';

            k++;
        }
        reverse(outPut.begin(), outPut.end());

        return outPut;
    }
};
int main()
{
    Solution obj;
    string S = "5F3Z-2e-9-w";
    int K = 4;
    cout << obj.licenseKeyFormatting(S, K);
}