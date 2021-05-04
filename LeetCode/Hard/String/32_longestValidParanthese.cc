// https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ret = 0;
        stack<char> stk;
        int k = s.length();
        for (int i = 0; i < s.length(); i++)
        { 
        }

        while (k--)
        {
            cout << k << endl;
        }
        return ret;
    }
};

int main()
{

    Solution obj;
    string s = ")()())";
    cout << obj.longestValidParentheses(s);
}