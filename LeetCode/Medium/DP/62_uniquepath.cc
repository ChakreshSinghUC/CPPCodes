// https://leetcode.com/problems/unique-paths/

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).

// How many possible unique paths are there?

#include <iostream>

using namespace std;

class Solution {
public:

int fact(int n)
    {
        if(n ==1) return 1;
        return n*fact(n-1);
    }
  int uniquePaths(int m, int n) {
    int ret;

    return ret;
  }
};

int main() {
  int m, n;
  Solution obj;
  cout << obj.fact(5);
}