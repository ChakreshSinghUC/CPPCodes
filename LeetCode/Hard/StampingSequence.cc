#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
  public:
    vector<int> movesToStamp(string stamp, string target)
    {
        bool S[26] = {false};
        vector<int> ret;
        vector<int> r = {NULL};
        int k = 0;
        while (k < stamp.length())
        {
            S[stamp[k] - 97] = true;
            k++;
        }
        k = 0;
        while (k < target.length())
        {
            if (!S[target[k] - 97])
            {
                if (target[k] != '?')
                {
                    return r;
                }
            }
            k++;
        }
        string rep;
        for (int i = 0; i < stamp.length(); i++)
            rep += '?';
        size_t pos = target.find(stamp);
        while (pos < target.length())
        {
            cout << left << "\t" << target << "\t" << pos << endl;

            ret.emplace_back(pos);
            target.replace(pos, stamp.length(), rep);
            pos = target.find(stamp);
        }
        string left;

        string double_stamp = stamp + stamp;

        for (int i = 0; i < target.length(); i++)
        {
            if (target[i] == '?')
            {
                bool f1 = true;
                bool f2 = true;

                if (!left.empty())
                {
                    size_t pos = stamp.find(left);
                    if (pos != 0 && pos < stamp.length())
                        f1 = false;
                    if (stamp.length() - left.length() != pos && pos < stamp.length())
                        f2 = false;
                    if (!f1 && !f2)
                        return r;
                    if (f1 && stamp.find(left) < stamp.length())
                    {
                        pos = target.find(left);
                        if (pos < target.length())
                        {
                            cout << left << "\t" << target << "\t" << target.find(left) << "\t"
                                 << "xx" << endl;
                            ret.emplace_back(target.find(left));
                            target.replace(target.find(left), stamp.length(), rep); //replace from front
                        }
                    }
                    if (f2 && stamp.find(left) < stamp.length())
                    {
                        pos = target.find(left);
                        if (pos < target.length())
                        {
                            cout << left << "\t" << target << "\t" << target.find(left) - stamp.length() + left.length() << "\t"
                                 << "yy" << endl;
                            ret.emplace_back(target.find(left) - stamp.length() + left.length());
                            target.replace(target.find(left), left.length(), "?"); //replace from back
                        }
                    }
                    if (double_stamp.find(left))
                    {
                        cout << target << "\t"
                             << "zz" << endl;
                        int i = 0;
                        string temp;
                        do
                        {
                            //cout << temp << "\t" << stamp.find(temp) << endl;
                            temp += left[i];
                            i++;
                        } while (stamp.find(temp) < stamp.length());
                        cout << "temp :" << temp << endl;
                    }
                    left.erase();
                }
            }
            else
                left += target[i];
        }
        if (!left.empty())
        {
            cout << target << "\t"
                 << "zxxz" << endl;
            size_t pos = stamp.find(left);
            if (stamp.length() - left.length() != pos)
                return r;
            if (target.find(left) < target.length())
                ret.emplace_back(target.find(left) - stamp.length() + left.length());
        }

        return ret;
    }
};
int main()
{
    Solution obj;
    vector<int> v;
    string stamp = "abca";
    string target = "aabcacaaabca";
    v = obj.movesToStamp(stamp, target);
    for (auto r : v)
        cout << r << "\t";
}