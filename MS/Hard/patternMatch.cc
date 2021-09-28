// https://leetcode.com/problems/wildcard-matching/solution/

#include<iostream>
#include<string>

using namespace std;

class Solution {
    void remove_duplicate_stars(string& p) {

        for (int i = 0; i < (int)p.length() - 1; i++)
            {
            if (i >= 0 && p[i] == '*' && p[i] == p[i + 1]) {
                p.erase(p.begin() + i);
                i--;
                }
            }
        }
public:
    bool isMatch(string s, string p) {
        remove_duplicate_stars(p);
        if (p == "*" || s == p)
            return true;
        if (s.empty() || p.empty())
            return false;

        if (p[0] == s[0] or p[0] == '?') {
            s.erase(s.begin() + 1);
            p.erase(p.begin() + 1);
            return isMatch(s, p);
            }
        if (p[0] == '*')
            {
            string m = s;
            m.erase(m.begin() + 1);
            string n = p;
            n.erase(n.begin() + 1);
            return (isMatch(m, p) || isMatch(s, n));
            }
        return false;
        }
    };

int main()
    {
    string s = "abcdcd", p = "ab****c*b";
    Solution obj;
    p.erase(p.begin() + 3);
    cout << obj.isMatch(s, p);

    }