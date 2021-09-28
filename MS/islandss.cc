#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int> > dir = { {-1, 1, 0, 0},
                           { 0, 0, -1,1} };
        auto isInsideGrid = [&](int row, int col) {
            return 0 <= row && row < M && 0 <= col && col < N;
            };


        vector<vector<bool>> visited(M, vector<bool>(N, 0));

        int answer = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    answer++;
                    queue<pair<int, int>> q;
                    q.push({ i,j });
                   // visited[i][j] = true;

                    while (!q.empty()) {
                        
                        pair<int, int> p = q.front();
                        q.pop();
                        //discover the neighbors
                        for (int d = 0; d < 4; d++)
                            {
                            int row = (p.first + dir[0][d]);
                            int col = (p.second + dir[1][d]);
                            if (isInsideGrid(row, col) && !visited[row][col] && grid[row][col] == 1) {
                                q.push({ row, col });
                                visited[row][col] = true;
                                }

                            }

                        }

                    }

                }
            }
            return answer;
            }
        };