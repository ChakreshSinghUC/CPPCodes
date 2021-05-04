#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    char shift(char a, int x)
    { 
        return (a + x);
    }
    string replaceDigits(string s)
    {
        if (s.length() == 1)
            return s;
        for (int i = 1; i < s.length(); i += 2)
            s[i] = shift(s[i - 1], s[i]-'0');
        return s;
    }
};

int main()
{
    Solution obj;
    string s = "a1c1e1";
    
    cout << obj.replaceDigits(s);
}