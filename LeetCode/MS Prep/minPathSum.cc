// https: // leetcode.com/problems/minimum-path-sum/
// This is not the correct solution. I coded a BFS traversal of the graph just
// for practice. The problem with this implementation is that once a cell in the
// grid is visited, we dont revisit it. But to find the minimum sum, we need to
// traverse all distict paths from {0, 0} to {m-1, n-1}

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    //   DFS : grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
    for (int i = grid.size() - 1; i >= 0; i--) {
      for (int j = grid[0].size() - 1; j >= 0; j--) {
        if (i == grid.size() - 1 && j != grid[0].size() - 1)
          grid[i][j] = grid[i][j] + grid[i][j + 1];
        else if (j == grid[0].size() - 1 && i != grid.size() - 1)
          grid[i][j] = grid[i][j] + grid[i + 1][j];
        else if (j != grid[0].size() - 1 && i != grid.size() - 1)
          grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
      }
    }
    return grid[0][0];
  }

  int minPathSum__incorrect_BFS_implementation(vector<vector<int>> &g) {
    vector<vector<int>> direction = {{0, 1}, {1, 0}};
    int max_path_sum = INT_MIN;

    int m = g.size();
    int n = g[0].size();

    auto isInside = [&](int row, int col) {
      return row >= 0 && row < m && col >= 0 && col < n;
    };

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        q.push({i, j});
        int path_sum = g[i][j];
        while (!q.empty()) {

          visited[i][j] = true;
          q.pop();
          for (int k = 0; k < direction.size(); k++) {
            int row = i + direction[k][0];
            int col = j + direction[k][1];
            if (isInside(row, col) && !visited[row][col]) {
              visited[row][col] = true;
              q.push({row, col});
              path_sum += g[row][col];
            }
          }
        }
        max_path_sum = max(path_sum, max_path_sum);
      }
    }
    return max_path_sum;
  }
};

int main() {
  Solution obj;
  vector<vector<int>> g = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << obj.minPathSum(g);
}
