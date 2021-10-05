
#include <iostream>
#include<vector> 
// board, mines
using namespace std;

Class Solution{

vector<vector<int>> B;
vector<vector<int>> visited;
int count_visited = 0;
int N;
public:

void initializeBoard(vector<vector<int>>& board, int mines)
    {

        B = board;
        N = mines;
        resize.visited(B.size(), B[0].size()) { {0} };
    }
int click(int r, int c)
    {
    if (visited[r][c] == 1)
    return -1;

    if (B[r][c] == -1)
        return 0;

    visited[r][c]++;
    count_visited++;


    if (count_visited == B.size() * B[0].size() - N) return 2;

    if (B[r][c] == 0)
        {
        updateNeighbourd(r, c);
        }
    refreshBoard();
    return 1;
    }

void updateNeighbour(int r, int c)
    {
    //    

    for (i)
        for (j)
            {
                  if (B[i][j] == 0 && visisted[i][j] != 1) {
                    click(i, j) //avoid mines; update visited. 
                      }
            }
    }
void refreshBoard() {
    //  ;
  }
    };

