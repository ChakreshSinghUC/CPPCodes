// https://leetcode.com/problems/generate-parentheses/description/
/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
  public:
    bool valid_paranthesis(string s)
    {
        bool flag = true;
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                stk.push(s[i]);
            if (s[i] == ')')
            {
                if (stk.empty())
                    return false;
                else
                    stk.pop();
            }
        }

        return flag;
    }
    vector<string> generateParenthesis(int n)
    {

        if (n <= 0)
            return {};
        vector<string> v;
        string s;
        for (int i = 0; i < n; i++)
            s += "(";
        for (int i = 0; i < n; i++)
            s += ")";
        do
        {
            if (valid_paranthesis(s))
                v.push_back(s);

        } while (next_permutation(s.begin(), s.end()));
        return v;
    }
};

int main()
{
    Solution obj;
    int count = 1;
    vector<string> v = obj.generateParenthesis(6);
    for (string i : v)
    {
        cout << count << ":\t" << i << endl;
        count++;
    }
}