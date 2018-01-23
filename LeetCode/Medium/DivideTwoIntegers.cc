// https://leetcode.com/problems/divide-two-integers/description/
// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return INT_MAX.
#include <iostream>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend > INT_MAX || dividend < INT_MIN || divisor > INT_MAX || divisor < INT_MIN)
            return INT_MAX;

        int dividend_sign = 1;
        int divisor_sign = 1;
        if (dividend < 0)
        {
            dividend_sign = -1;
            dividend = -1 * dividend;
        }
        if (divisor < 0)
        {
            divisor_sign = -1;
            divisor = -1 * divisor;
        }
        unsigned denom = divisor;
        unsigned current = 1;
        unsigned answer = 0;
        
        if (denom > dividend)
            return 0;

        if (denom == dividend)
            return 1;

        while (denom <= dividend)
        {
            denom <<= 1;
            current <<= 1;
        }

        denom >>= 1;
        current >>= 1;

        while (current != 0)
        {
            if (dividend >= denom)
            {
                dividend -= denom;
                answer |= current;
            }
            current >>= 1;
            denom >>= 1;
        }
        answer = (dividend_sign * divisor_sign * answer);
        cout << "Here: " << answer << endl;
        if (answer > INT_MAX || answer < INT_MIN)
            return INT_MAX;

        return answer;
    }
};
int main()
{
    Solution o;
    cout << o.divide(-2147483648, -1);
}