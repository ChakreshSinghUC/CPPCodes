#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> shortestToChar(string S, char C)
    {
        int itr = 0;
        while (itr < S.length())
        {
            if (S[itr] == C)
                cout << itr << " ";
            itr++;
        }
        cout << endl;
        vector<int> ret;
        return ret;
    }
};
int main()
{
    Solution obj;
    string S = "chakreshsinegh";
    char C = 'e';
    vector<int> out = obj.shortestToChar(S, C);
    for (auto i : out)
        cout << i << " ";
}