#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    // This function returns the longest palindrome substring (LPS)
    // of str[].
    string longestPalindrome(string str)
    {
        int maxLength = 1; // The result (length of LPS)

        int start = 0;
        int len = str.length();

        int low, high;

        // One by one consider every character as center point of
        // even and odd length palindromes
        for (int i = 1; i < len; ++i)
        {
            // Find the longest even length palindrome with center points
            // as i-1 and i.
            low = i - 1;
            high = i;
            while (low >= 0 && high < len && str[low] == str[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }

            // Find the longest odd length palindrome with center
            // point as i
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < len && str[low] == str[high])
            {
                if (high - low + 1 > maxLength)
                {
                    start = low;
                    maxLength = high - low + 1;
                }
                --low;
                ++high;
            }
        }
        return str.substr(start, maxLength);
    }
};
int main()
{
    Solution obj;
    cout << obj.longestPalindrome("gulposhkaheenitraayenkaheen");
}