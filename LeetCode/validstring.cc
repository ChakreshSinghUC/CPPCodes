#include <iostream>
using namespace std;

class Solution
{
  public:
    bool isNumber(string s)
    {
        bool flag = true;
        int c = 0;
        int loc;
        int num = 0;
        int first_num_loc = -1, last_num_loc = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (48 <= s[i] && s[i] <= 58)
            {
                if (first_num_loc == -1)
                    first_num_loc = i;
                last_num_loc = i;
            }
            if (!((48 <= s[i] && s[i] <= 58) || s[i] == 32 || s[i] == 46))
            {
                flag = false;
            }
            //count the number of dots in the string
            if (s[i] == 46)
            {
                c++;
                loc = i;
            }
        }

        if (c > 1)
            flag = false;
        else if (c == 1 && loc < last_num_loc)
            flag = true;
        return flag;
    }
};

int main()
{
    Solution obj;
    string s = "1 0";
    (obj.isNumber(s) && s != "")
        ? cout << "True"
        : cout << "False";
}