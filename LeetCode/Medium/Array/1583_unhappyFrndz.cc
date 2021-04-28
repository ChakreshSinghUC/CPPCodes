// https://leetcode.com/problems/count-unhappy-friends/

#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        // Unhappiness conditions: A friend x is unhappy if x is paired with y and there exists a friend u who
        // is paired with v but:

        // x prefers u over y, and
        // u prefers x over v.
        
        int count = 0;

        return count;
    }
};
int main()
{

    int n; // always even - given.
    // For each person i, preferences[i] contains a list of friends sorted in the order of preference.
    vector<vector<int>> preferences;
    // All the friends are divided into pairs. The pairings are given in a list pairs,
    //  where pairs[i] = [xi, yi] denotes xi is paired with yi and yi is paired with xi.
    vector<vector<int>> pairs;
}