#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findMinStep(string board, string hand)
    {
        int A[5] = {0};
        int H[5] = {0};
        for (int i = 0; i < board.length(); i++)
        {
            if (board[i] == 'R')
            {
                A[0]++;
            }
            else if (board[i] == 'Y')
            {
                A[1]++;
            }
            else if (board[i] == 'B')
            {
                A[2]++;
            }
            else if (board[i] == 'G')
            {
                A[3]++;
            }
            else if (board[i] == 'W')
            {
                A[4]++;
            }
        }
        for (int i = 0; i < board.length(); i++)
        {
            if (hand[i] == 'R')
            {
                H[0]++;
            }
            else if (hand[i] == 'Y')
            {
                H[1]++;
            }
            else if (hand[i] == 'B')
            {
                H[2]++;
            }
            else if (hand[i] == 'G')
            {
                H[3]++;
            }
            else if (hand[i] == 'W')
            {
                H[4]++;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            //cout << board[i] << "\t" << hand[i] << endl;
            if (A[i] + H[i] > 0 && A[i] + H[i] < 3)
                return false;
        }
     
        return true;
    }
};
int main()
{
    Solution o;
    string board = "WRRBBW", hand = "RB";
    cout << o.findMinStep(board, hand);
}