#include <iostream>
using namespace std;
bool isPalindromic(string s)
{
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if (s[i]!=s[j])  return false; 
    }
    return true;
}
int main()
{
    string s = "chakrkahc";
    s.append("schakrkahc");
    cout<<isPalindromic(s);
}