// https://leetcode.com/problems/remove-vowels-from-a-string/
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string removeVowels(string s)
    {
        string ret;
        for (int i = 0; i < s.size(); i++)
        {
            if (char(s[i]) == 'a' || char(s[i]) == 'e' || char(s[i]) == 'i' || char(s[i]) == 'o' || char(s[i]) == 'u')
                ;
            else
                ret += s[i];
        }
        return ret;
    }
};
int main()
{
    string s = "leetcodeisacommunityforcoders";
    Solution obj;
    cout << obj.removeVowels(s);
}