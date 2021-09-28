#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        const array<array<int, 2>, 4> kShift = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        int dir = 0, x = 0, y = 0;
        vector<int> spiral_ordering;
        for (int i = 0; i < matrix.size() * matrix.size(); ++i)
        {
            spiral_ordering.emplace_back(matrix[x][y]);
            matrix[x][y] = 0;

            int next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
            if (next_x < 0 || next_x >= matrix.size() || next_y < 0 || next_y >= matrix.size() || matrix[next_x][next_y] == 0)
            {
                dir = (dir + 1) % 4;
                next_x = x + kShift[dir][0], next_y = y + kShift[dir][1];
            }
            x = next_x, y = next_y;
        }
        return spiral_ordering;
    }
};
int main()
{
}