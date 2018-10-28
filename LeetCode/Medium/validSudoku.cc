// https://leetcode.com/problems/valid-sudoku/
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int chartonum(char ch)
    {
        switch (ch)
        {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        }
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int A[9];
        // Each row must contain the digits 1-9 without repetition.
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        // Each column must contain the digits 1-9 without repetition
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        // Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 3; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 6; i < 9; i++)
        {
            for (int j = 0; j < 3; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 3; j < 6; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 3; i < 6; i++)
        {
            for (int j = 3; j < 6; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 6; i < 9; i++)
        {
            for (int j = 3; j < 6; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 6; j < 9; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 3; i < 6; i++)
        {
            for (int j = 6; j < 9; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }

        for (int i = 6; i < 9; i++)
        {
            for (int j = 6; j < 9; j++)

            {
                A[chartonum(board[i][j]) - 1]++;
                if (A[chartonum(board[i][j]) - 1] > 1)
                    return false;
            }
            for (int i = 0; i < 9; i++)
                A[i] = 0;
        }
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