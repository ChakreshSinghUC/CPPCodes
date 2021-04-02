#include<iostream>
#include<map>
#include<vector>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        
        
        for (int i = 0; i < board.size(); i++)
        { //row-wise traversal
            map<int, int> mp;
            for (int j = 0; j < board[i].size(); j++)
            { 
                if (board[i][j] != '.')
                {
                    if (mp.find(board[i][j] - 48) == mp.end())
                        mp[board[i][j] - 48] = 1;
                    else
                        return 0;
                }
            } 
        }

        for (int i = 0; i < board.size(); i++)
        { //colum-wise traversal
            map<int, int> mp;
            for (int j = 0; j < board[i].size(); j++)
                if (board[j][i] != '.')
                {
                    if (mp.find(board[j][i] - 48) == mp.end())
                        mp[board[j][i] - 48] = 1;
                    else
                        return 0;
                }
        }

        for (int m = 0; m < 7; m += 3)
        {//sub-grid traversal
            for (int n = 0; n < 7; n += 3)
            {
                map<int, int> mp;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i + m][j + n] != '.')
                        {
                            if (mp.find(board[i + m][j + n] - 48) == mp.end())
                                mp[board[i + m][j + n] - 48] = 1;
                            else
                                return 0;
                        }
                    }
                }
            }
        }
        
        return 1;
    }
};



int main()
{

    //ToDo
}