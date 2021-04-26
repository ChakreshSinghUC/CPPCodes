
// https://leetcode.com/problems/is-subsequence/submissions/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == "" && t == "")
            return 1;

        if (s.size() > t.size())
            return 0;
        int j = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[j] == t[i])
                j++;
            if (j == s.size())
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    cout << "Is Subsequence? " << obj.isSubsequence("abc", "ascbankac");
}