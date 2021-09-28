#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int minFallingPathSum(vector<vector<int>> A)
    {
        int N = A[0].size();
        for (int r = N - 2; r >= 0; --r)
        {
            for (int c = 0; c < N; ++c)
            {
                // best = min(A[r+1][c-1], A[r+1][c], A[r+1][c+1])
                int best = A[r + 1][c];
                if (c > 0)
                    best = min(best, A[r + 1][c - 1]);
                if (c + 1 < N)
                    best = min(best, A[r + 1][c + 1]);
                A[r][c] += best;
            }
        }

        int ans = INT_MAX;
        for (int x : A[0])
            ans = min(ans, x);
        return ans;
    }
};
 int main()
{
    Solution obj;
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Minimum falling path is: " << obj.minFallingPathSum(A);
}