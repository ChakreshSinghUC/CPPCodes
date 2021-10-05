// https://leetcode.com/problems/matrix-block-sum/

// Given a m x n matrix mat and an integer k, return a matrix answer where each
// answer[i][j] is the sum of all elements mat[r][c] for:

// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > matrixBlockSum(vector<vector<int> > &mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int> > answer(m, vector<int>(n, 0));
    if (k == 0)
      answer = mat;
 

      

    return answer;
  }
};

int main() {
  vector<vector<int> > mat;
  int k;
  Solution obj;
  vector<vector<int> > ans = obj.matrixBlockSum(mat, k);
}