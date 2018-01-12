// https://leetcode.com/problems/sqrtx/description/
/**Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
**/
#include <iostream>
using namespace std;
class Solution
{
  public:
    int mySqrt(int x)
    {
        return 1;
    }
};
int main()
{
    int n = 10;
    Solution obj;
    cout << obj.mySqrt(n);
}