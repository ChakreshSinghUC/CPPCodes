// https://leetcode.com/problems/matrix-diagonal-sum/

#include <iostream>
#include <vector>
// return sum of promary and secpndary diagonals.
using namespace std;

class Solution {
public:
  int diagonalSum(vector<vector<int> > &mat) {
    int sum = 0;
    for (int i = 0; i < mat.size(); i++) {
      int j = mat.size() - 1 - i;
      int primary_doagonal, second_digonal;

      primary_doagonal = mat[i][i];
      second_digonal = mat[i][j];
      if (i != j)
        sum += second_digonal;
      sum += primary_doagonal;
    }
    return sum;
  }
  int diagonalSum_slow(vector<vector<int> > &mat) {
    int sum = 0;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (i + j == mat.size() - 1 || i == j)
          sum += mat[i][j];
      }
    }
    return sum;
  }
};

int main() {
  Solution obj;
  vector<vector<int> > mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << obj.diagonalSum(mat);
}