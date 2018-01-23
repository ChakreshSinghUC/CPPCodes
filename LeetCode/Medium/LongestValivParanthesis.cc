//https://leetcode.com/problems/longest-valid-parentheses/description/
//find the  the longest valid parentheses substring
//example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            //code here
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    string s = ")(())()(";
    cout << obj.longestValidParentheses(s) << endl;
}