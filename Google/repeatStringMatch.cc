//https://leetcode.com/explore/featured/card/google/67/sql-2/469/
/***Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
***/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int repeatedStringMatch(string A, string B)
    {
    }
};
int main()
{
    Solution obj;
    string A, B;
    A = "aaab";
    B = "aab";
    cout << obj.repeatedStringMatch(A, B);
}