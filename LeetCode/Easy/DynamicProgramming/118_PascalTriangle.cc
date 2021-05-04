// https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {

    vector<vector<int>> triangle;
    if (numRows == 0)
      return triangle;

    vector<int> row;
    row.push_back(1);
    triangle.push_back(row);

    for (int i = 1; i < numRows; i++) {
      vector<int> _row;
      vector<int> _prev_row = triangle[i - 1];

      _row.push_back(1);

      for (int j = 1; j < i; j++)
        _row.push_back(_prev_row[j - 1] + _prev_row[j]);

      _row.push_back(1);
      triangle.push_back(_row);
    }

    return triangle;
  }
};

int main() {
  Solution obj;
  vector<vector<int>> t = obj.generate(5);

  for (int i = 0; i < t.size(); i++) {
    for (int j = 0; j < t[i].size(); j++)
      cout << t[i][j] << " ";
    cout << endl;
  }
}