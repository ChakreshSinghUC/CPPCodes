#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> t;
    vector<string> s;
    int count = 0;
    size_t pos = INT_MAX;
    int repeatedStringMatch(string A, string B)
    {

        while (B.find(A) != std::string::npos)
        {
            if (B.substr(0, B.find(A)) != A)
            {
                s.emplace_back(B.substr(0, B.find(A)));
            } 
            t.emplace_back(B.find(A));
            count++;

            B = B.substr(B.find(A) + A.size());
            if (A.size() <= B.size())
                repeatedStringMatch(A, B);
            else
                s.emplace_back(B);
        }

        for (auto i : s)
        {
            cout << i << endl;
            if (s[0].size() != 0 && (A.find(s[0]) == 0 ||
                                     A.find(s[0]) == std::string::npos))
            {
                return -1;
            }
            else
                count++;
            if (s[1].size() != 0 && (A.find(s[1]) != 0 || A.find(s[1]) == std::string::npos))
            {
                return -1;
            }
            else
                count++;
        }
        return count;
    }
};
int main()
{
    Solution obj;
    string A = "abcd", B = "cdabcdabcdab";
    cout << obj.repeatedStringMatch(A, B) << endl;
}