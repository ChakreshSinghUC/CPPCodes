//https://leetcode.com/problems/shortest-palindrome/description/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    string shortestPalindrome(string s)
    {
        int len = 0;
        int mid_index = s.length() / 2;
        int max_length = 0;
        string ret;
        for (int i = mid_index; i >= 0; i--)
        {

            string r = s.substr(i + 1, i);
            reverse(r.begin(), r.end());
            if (s.substr(0, i) == r && i > max_length)
            {
                ret = s.substr(2 * i + 1, s.length() - 2 * i);
                max_length = i;
            }
        }
        if (ret.empty())
        {
            ret = s.substr(1, s.length() - 1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    string s = "abbad";
    Solution obj;
    cout << obj.shortestPalindrome(s) + s;
}