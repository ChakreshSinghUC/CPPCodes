// https://www.scaler.com/academy/mentee-dashboard/class/7326/assignment/problems/9961?navref=cl_tt_nv

// Q2.Prefix Matching Problem Description
//             We have a list of lexicographically sorted strings A
//                 .We also have a string B
//                 .We need the first and last indexes of strings from A which
//                 are
//                     having their prefix as B.A can contain duplicate strings
//                 .
//         Return[-1, -1] if no such prefix exists.
//         Problem Constraints
// 1 <= | A | <= 10^5
// 1 <= ∑| A[i] | <= 10^6
// 1 <= | B | <= 10^55

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> solve(vector<string> &A, string B) {

    auto isprefix = [](string A, string B) {
      if (A == "" && B == "")
        return true;

      if (A.length() == B.length())
        return (A == B);

      if (A.length() > B.length())
        return false;

      for (int i = 0; i < A.length(); i++) {
        if (A[i] != B[i])
          return false;
      }
      return true;
    };

    int l = 0;
    int r = A.size() - 1;
    int __l = -1;
    int __r = B.length();

    while (l < r) {
      if (isprefix(A[l], B))
        __l = min(__l, l);

      if (isprefix(A[r], B))
        __r = min(__r, r);
    }

    if (__l == -1 || __r == B.length())
      return {-1, -1};

    return {__l, __r};
  }
};
int main() {}