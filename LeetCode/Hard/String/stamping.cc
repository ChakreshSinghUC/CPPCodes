// https://leetcode.com/problems/stamping-the-sequence/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> ret;
    void substrPosition(string s, string &t, int &p)
    {
        string str;
        for (int i = 0; i < s.length(); i++)
        {
            str += '*';
        }
        for (int i = p; i < t.length() - s.length() + 1; i++)
        {
            if (t.substr(i, s.length()) == s)
            {
                ret.push_back(i);
                t.replace(i, s.length(), str);
                p = i + s.length() + 1;
            }
        }
    }

    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> r;
        for (int i = 0; i < target.length(); i++)
        {
            cout << i << ": ";
            substrPosition(stamp, target, i);
            cout << " : " << i << endl;
        }
        cout << target;
        return r;
    }
};
int main()
{
    string stamp = "abc", target = "ababcabcaacccabc";
    Solution obj;
    vector<int> r = obj.movesToStamp(stamp, target);

    for (auto a : r)
        cout << a << ", ";
}