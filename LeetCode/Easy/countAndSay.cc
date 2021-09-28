#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string helper_countAndSay(string n)
    {
        
        int digits = n.length();
        int count = 1;
        int i = 0;
        string ret;
        int temp;
        for (int i = 0; i < digits; i++)
        {
            temp = i;
            while (i != digits - 1 && n[i] == n[i + 1])
            {
                temp = i;
                count++;
                i++;
            }
            ret += 48 + count;
            ret += n[i];
            count = 1;
        }
        return ret;
    }
    string countAndSay(int n)
    {
        string ret = "1";
        if (n == 1)
            return ret;
        for (int i = 0; i < n - 1; i++)
        {
        
            ret = helper_countAndSay(ret);
        }
        return ret;
        
    }
};
int main()
{
    int n = 13;
    Solution obj;
    cout << obj.countAndSay(n);
}
