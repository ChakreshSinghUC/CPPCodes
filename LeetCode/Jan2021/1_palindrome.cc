// https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3588/

#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        if (s.length() < 2)
            return 1;
        map<char, int> m;
        int i = 0;
        while (i < s.length())
        {
            if (m.find(s[i]) == m.end())
                m[s[i]] = 1;
            else
                m[s[i]]++;

            i++;
        }
        int count_odd = 0;
        for (auto a : m)
        {
            if (a.second % 2 == 1)
                count_odd++;
        }
        return (s.length() % 2 == count_odd);
    }
};
int main()
{
    Solution o;
    cout << o.canPermutePalindrome("aaa");
}