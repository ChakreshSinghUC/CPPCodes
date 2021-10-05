#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        string t;


        vector<vector<int>> dp(num.length() + 1, { 0, 0, 0 });

        dp[0][0] = num[0] - '0';


        for (int i = 1; i < num.length(); i++)
            {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    {
                    dp[i][j] = dp[i - 1][k] - num[i] - '0';
                    dp[i][j] = dp[i - 1][k] + num[i] - '0';
                    dp[i][j] = dp[i - 1][k] * num[i] - '0';
                    cout << dp[i][j] << endl;
                    }
                }
            }
        return ret;
        }
    };
int main()
    {
    string num = "123";
    int target = 6;
    Solution obj;
    vector<string> s = obj.addOperators(num, target);

    for (auto i : s)
        {
        cout << i;
        }
    }