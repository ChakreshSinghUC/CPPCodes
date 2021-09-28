
//check is a string of characters is Palindrome.
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
     //   system("ls");
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    cout << obj.isPalindrome("12a21");
}