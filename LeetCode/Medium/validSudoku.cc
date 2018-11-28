// https://leetcode.com/problems/valid-sudoku/
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  vector<vector<char>> b;
    bool isValidSudoku(const vector<vector<char>> &board)
    {b= board;
        for (int i = 0; i < board.size(); ++i)
        {
            if (HasDuplicate( i, i + 1, 0, board.size()))
            {
                return false;
            }
        }

        for (int j = 0; j < board.size(); ++j)
        {
            if (HasDuplicate( 0, board.size(), j, j + 1))
                return false;
        }
        int region_size = sqrt(board.size());
        for (int i = 0; i < region_size; ++i)
        {
            for (int j = 0; j < region_size; ++j)
            {
                if (HasDuplicate( region_size * i, region_size * (i + 1), region_size * j, region_size * (j + 1)))
                    return false;
            }
        }
    }
    bool HasDuplicate( int start_row, int end_row, int start_col, int end_col)
    {
        deque<bool> is_present(b.size() + 1, false);
        for (int i = start_row; i < end_row; ++i)
        {
            for (int j = start_col; j < end_col; ++j)
            {
                if (b[i][j] != 0 &&
                    is_present[b[i][j]])
                {
                    return true;
                }
                is_present[b[i][j]] = true;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<char>> board;
    Solution obj;
    // board[0][0] = '5';
    // board[0][1] = '3';
    // board[0][4] = '7';
    // board[0][0] =
    //     board[0][0] =
    //         board[0][0] =
    //             board[0][0] =
    //                 board[0][0] =
    //                     board[0][0] =
    //                         board[0][0] =

    bool f = obj.isValidSudoku(board);
    /* =
        {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
         {"6", ".", ".", "1", "9", "5", ".", ".", "."},
         {".", "9", "8", ".", ".", ".", ".", "6", "."},
         {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
         {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
         {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
         {".", "6", ".", ".", ".", ".", "2", "8", "."},
         {".", ".", ".", "4", "1", "9", ".", ".", "5"},
         {".", ".", ".", ".", "8", ".", ".", "7", "9"}};*/
}