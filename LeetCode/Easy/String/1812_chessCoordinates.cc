// https://leetcode.com/problems/determine-color-of-a-chessboard-square/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        // Return true if the square is white, and false if the square is black.
        return (((coordinates[0] - 'a') % 2 == 0 && (coordinates[1] - '1') % 2 == 0) || ((coordinates[0] - 'a') % 2 == 1 && (coordinates[1] - '1') % 2 == 1))
                   ? 0
                   : 1;
    }
};

int main()
{
    string coordinates = "a1";
    Solution obj;
    cout << obj.squareIsWhite(coordinates);
}