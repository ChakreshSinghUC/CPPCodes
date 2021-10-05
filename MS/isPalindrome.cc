
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
<<<<<<< HEAD
        system("ls");
=======
     //   system("ls");
>>>>>>> 77ecdd742f4f0c2b0f347b22fa9c7fd98e3bbe7f
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
<<<<<<< HEAD
    cout << obj.isPalindrome("12a");
=======
    cout << obj.isPalindrome("12a21");
>>>>>>> 77ecdd742f4f0c2b0f347b22fa9c7fd98e3bbe7f
}