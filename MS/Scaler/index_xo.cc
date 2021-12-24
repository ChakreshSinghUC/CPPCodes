// https://www.scaler.com/academy/mentee-dashboard/class/7326/assignment/problems/10054/hints?navref=cl_pb_nv_tb

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(string A) {
    int n = A.size();
    vector<int> prex(n, 0);
    vector<int> sufx(n, 0);
    for (int i = 0; i < n; i++) {
      if (A[i] == 'x') {
        prex[i] = i;
      } else {
        if (i == 0) {
          prex[i] = -1;
        } else {
          prex[i] = prex[i - 1];
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (A[i] == 'x') {
        sufx[i] = i;
      } else {
        if (i == n - 1) {
          sufx[i] = -1;
        } else {
          sufx[i] = sufx[i + 1];
        }
      }
    }
    int ans = 1e7;
    for (int i = 0; i < n; i++) {
      if (A[i] == 'o') {
        if (prex[i] != -1)
          ans = min(ans, i - prex[i]);
        if (sufx[i] != -1)
          ans = min(ans, sufx[i] - i);
      }
    }
    if (ans == 1e7) {
      return -1;
    }
    return ans;
  }
};
int main() {
  string A = "x....o...o....x..x...x";
  Solution o;
  cout<<o.solve(A);
}