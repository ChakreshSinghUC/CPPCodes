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
// Algorithm:
// 1) Start with 'start' = 0, end = 'x',
// 2) Do following while 'start' is smaller than or equal to 'end'.
//       a) Compute 'mid' as (start + end)/2
//       b) compare mid*mid with x.
//       c) If x is equal to mid*mid, return mid.
//       d) If x is greater, do binary search between mid+1 and end. In this case, we also update ans (Note that we need floor).
//       e) If x is smaller, do binary search between start and mid-1

#include <iostream>
using namespace std;

class Solution
{
  public:
    int mySqrt(int x)
    {
        // Base cases
        if (x == 0 || x == 1)
            return x;

        // Do Binary Search for floor(sqrt(x))
        int start = 0, end = x/2, ans;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            // If x is a perfect square
            if (mid * mid == x)
                return mid;

            // Since we need floor, we update answer when mid*mid is
            // smaller than x, and move closer to sqrt(x)
            if (mid * mid < x)
            {
                start = mid + 1;
                ans = mid;
            }
            else // If mid*mid is greater than x
                end = mid - 1;
        }
        return ans;
    }
};

int main()
{
    int n = 2147395599;
    Solution obj;
    cout << obj.mySqrt(n);
}