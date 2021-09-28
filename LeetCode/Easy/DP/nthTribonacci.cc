// https://leetcode.com/problems/n-th-tribonacci-number/
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int tribonacci_dp(int n) {
    //   dp approach

    vector<int> dp{0, 1, 1};

    if(n<3)
      return dp[n];

    for (int i = 3; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
  }
  int tribonacci_rec(int n) {
    //   recursive approach
    if (n == 0)
      return 0;
    if (n == 1 || n == 2)
      return 1;
    return tribonacci_rec(n - 1) + tribonacci_rec(n - 2) +
           tribonacci_rec(n - 3);
  }
};
int main() {
  int n = 25;
  Solution obj;
  cout << "Recursive: "<< obj.tribonacci_rec(n)<<endl;
  cout << "DP: " << obj.tribonacci_dp(n) << endl;
}