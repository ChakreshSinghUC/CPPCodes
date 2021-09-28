/*************************************************************************************************************************
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example:
 * Input: "cbbd"
 * Output: "bb"
*************************************************************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if (s.length() <= 1)
            return true;
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            if (s[l] != s[r])
                return false;
            if (l >= r)
                return true;
        }
    }
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s;
        int l = 0;
        int r = s.length() - 1;
        string output;
        int len = 0;
        while (l < r)
        {
            do
            {
                if (len < r - l + 1)
                {
                    if (isPalindrome(s.substr(l, r - l + 1)))
                    {
                        output = s.substr(l, r - l + 1);
                        len = output.length();
                    }
                }
                r--;
            } while (l < r);
            l++;
            r = s.length() - 1;
        }
        if (output == "")
            output = s[0];
        return output;
    }
};
int main()
{
    Solution obj;
    cout << obj.longestPalindrome("chakreshsingh");
}
