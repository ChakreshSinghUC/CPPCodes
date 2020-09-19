#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if (s == "")
            return true;
        locale loc;
        string str, input;
        for (string::size_type i = 0; i < s.length(); ++i)
            str += tolower(s[i], loc);
        for (int i = 0; i < str.length(); i++)
        {
            if (isalnum(str[i]))
                input += str[i];
        }

        if (input.length() <= 1)
            return true;
        int l = 0;
        int r = input.length() - 1;
        while (l < r)
        {
            if (input[l] == input[r])
            {
                l++;
                r--;
            }
            if (input[l] != input[r])
                return false;
            if (l >= r)
                return true;
        }
    }
};
int main()
{

    Solution obj;
    string s = "a.";

    cout << obj.isPalindrome(s);
}