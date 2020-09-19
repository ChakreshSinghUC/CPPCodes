//  Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
#include <iostream>
using namespace std;
class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
            return -1;
        else if (haystack == needle)
            return 0;
        else if (haystack.size() == needle.size() && haystack != needle)
            return -1;

        int size = haystack.size() - needle.size();
        for (int i = 0; i <= size; i++)
        {
            string s;
            for (int j = 0; j < needle.size(); j++)
            {
                s += haystack[i + j];
            }
            if (s == needle)
                return i;
        }
        return -1;
    }
};
int main()
{
    string haystack = "hello";
    string needle = "ll";
    Solution obj;
    cout << obj.strStr(haystack, needle);
}