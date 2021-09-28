//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <vector> 
using namespace std;

class Solution
{

public:
    string digitToString(char ch)
    {

        string a;
        switch (ch)
        {
        case '2':
            a = "abc";
            break;
        case '3':
            a = "def";
            break;
        case '4':
            a = "ghi";
            break;
        case '5':
            a = "jkl";
            break;
        case '6':
            a = "mno";
            break;
        case '7':
            a = "pqrs";
            break;
        case '8':
            a = "tuv";
            break;
        case '9':
            a = "wxyz";
            break;

        default:
            break;
        }
        return a;
    }

    vector<string> setMultiply(vector<string> b, string a)
    {

        vector<string> p;
        if (b.empty())
        {
            for (auto i : a)
                p.push_back(string(1, i));
            return p;
        }

        for (auto i : b)
        {
            for (auto j : a)
                p.push_back(i + j);
        }

        return p;
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> vec;
        int len = digits.length();
        string a;

        for (int i = 0; i < digits.length(); i++)
        {
            string a;
            if (digits[i] != '1' || digits[i] != '0')
            {
                a = digitToString(digits[i]);
                vec = setMultiply(vec, a);
            }
            // cout << a << endl;
        }
        return vec;
    }
};

int main()
{
    Solution obj;
    string d = "2312";
    vector<string> v = obj.letterCombinations(d); 
}