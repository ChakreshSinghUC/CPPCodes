// https://leetcode.com/problems/robot-bounded-in-circle/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int org_x = 0, org_y = 0;
        int nxt_x = 0, nxt_y = 0;
        int dir = 0;

        for (int i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'G')
            {
                if (dir % 4 == 0)
                    //positive x direction
                    nxt_x++;
                if ((dir + 4) % 4 == 1)
                    //positive y direction
                    nxt_y++;
                if ((dir + 4) % 4 == 2)
                    //negative x direction
                    nxt_x--;
                if ((dir + 4) % 4 == 3)
                    //negative y direction
                    nxt_y--;
            }

            if (instructions[i] == 'L')
                dir = (dir + 1) % 4;
            if (instructions[i] == 'R')
                dir = (dir - 1) % 4;
        }

        return (org_x == nxt_x && org_y == nxt_y);
    }
};

int main()
{
    string s = "GL";
    Solution obj;
    cout << obj.isRobotBounded(s);
}