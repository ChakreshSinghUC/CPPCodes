#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int longestCommonSubsequence(string str1, string str2)
	{
		// Write your code here.

		int m = (int)str1.length();
		int n = (int)str2.length();
		vector<vector<int>> C(m + 1, vector<int>(n + 1, 0));

		//     for (int i = 0; i<=m; i++)
		//         C[i][0] = 0;
		//     for (int i = 0; i<=n; i++)
		//         C[0][i] = 0;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
				cout << C[i][j] << " ";
			cout << "\n";
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (str1[i] == str2[j])
					C[i][j] = C[i - 1][j - 1] + 1;
				else
					C[i][j] = max(C[i][j - 1], C[i - 1][j]);
			}
		}
		return C[m][n];
	}
};
int main()
{
	Solution o;
	cout << o.longestCommonSubsequence("XKYKZPW", "ZXVVYZW");
}
