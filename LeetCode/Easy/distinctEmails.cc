#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

class Solution
{
  public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> s;

        for (auto a : emails)
        {
            int i = 0;
            int l = INT_MAX;
            int p = 0;

            while (a[i] != '@')
            {
                if (a[i] == '.' && l != -1)
                    a.erase(a.begin() + i);
                if (a[i] == '+')
                    l = min(l, i);

                i++;
            }
            a.erase(l, i - l);
            s.insert(a);
            //cout << a << endl;
        }
        return s.size();
    }
};
int main()
{
    Solution obj;
    vector<string> emails;
    emails.push_back("singh.chak+resh@gmail.com");
    cout << obj.numUniqueEmails(emails);
}