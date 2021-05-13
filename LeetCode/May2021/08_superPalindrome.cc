// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool __isPalindrome(string s)
    {
        string _s = s;
        reverse(s.begin(), s.end());
        return (_s == s);
    }

    bool isPalindrome(string s)
    {
        if (s.length() < 2)
            return 1;
        map<char, int> mymap;
        int count_odd = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mymap.find(s[i]) == mymap.end())
                mymap[s[i]] = 1;
            else
                mymap[s[i]]++;
        }
        for (auto a : mymap)
        {
            if (a.second % 2)
                count_odd++;
        }
        return (s.length() % 2 == count_odd);
    }
    int superpalindromesInRange(string left, string right)
    {
        int k = 0;
        long long int num1 = 0, num2 = 0;
        while (k < left.length())
        {
            num1 = (num1 * 10) + left[k] - '0';
            k++;
        }
        k = 0;
        while (k < right.length())
        {
            num2 = (num2 * 10) + right[k] - '0';
            k++;
        }
     //   cout << num1 << "\t" << num2 << endl;
        return (sqrtl(num1)==sqrtl(num2));
    }
};

int main()
{
    Solution o;
    // cout << o.superpalindromesInRange("4", "1000");
    cout << (sqrtl(1000000000000000000) == sqrtl(1000000000000000000));
}