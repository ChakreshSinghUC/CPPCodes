#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> ret;
        string prefixStamp[stamp.length()];
        string postfixStamp[stamp.length()];
        for (int i = 0; i < stamp.length(); i++)
        {
            int k = 0;
            while (k < stamp.length())
            {
                if (k < stamp.length() - i)
                {
                    prefixStamp[i] += stamp[k];
                    postfixStamp[i] += '?';
                }
                else
                {
                    prefixStamp[i] += '?';
                    postfixStamp[i] += stamp[k];
                }
                k++;
            }
        }

        for (int i = 0; i < stamp.length(); i++)
        {
            while (target.find(prefixStamp[i]) != std::string::npos)
            {
                ret.emplace_back(target.find(prefixStamp[i]));
                target.replace(target.find(prefixStamp[i]), stamp.length(), postfixStamp[0]);
            }
        }

        for (int i = stamp.length() - 1; i >= 0; i--)
        {
            while (target.find(postfixStamp[i]) != std::string::npos && i != 0)
            {
                ret.emplace_back(target.find(postfixStamp[i]));
                target.replace(target.find(postfixStamp[i]), stamp.length(), postfixStamp[0]);
            }
        }
        for (int i = 0; i < stamp.length(); i++)
        {
            while (target.find(postfixStamp[i]) != std::string::npos && i != 0)
            {
                ret.emplace_back(target.find(postfixStamp[i]));
                target.replace(target.find(postfixStamp[i]), stamp.length(), postfixStamp[0]);
            }
        }

        for (int i = 0; i < stamp.length(); i++)
        {
            while (target.find(prefixStamp[i]) != std::string::npos)
            {
                ret.emplace_back(target.find(prefixStamp[i]));
                target.replace(target.find(prefixStamp[i]), stamp.length(), postfixStamp[0]);
            }
        }

        for (int i = stamp.length() - 1; i >= 0; i--)
        {
            while (target.find(postfixStamp[i]) != std::string::npos && i != 0)
            {
                ret.emplace_back(target.find(postfixStamp[i]));
                target.replace(target.find(postfixStamp[i]), stamp.length(), postfixStamp[0]);
            }
        }

        for (int i = 0; i < target.length(); i++)
            if (target[i] != '?')
                return {};

        cout << target << endl;
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    Solution obj;
    vector<int> v;
    string stamp = "dfe";
    string target =
        "ddfdfedfdfeefee";
    v = obj.movesToStamp(stamp, target);
    for (auto r : v)
        cout << r << "\t";
}