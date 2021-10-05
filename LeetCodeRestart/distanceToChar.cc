#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
<<<<<<< HEAD
=======
//edited by chakresh
>>>>>>> 77ecdd742f4f0c2b0f347b22fa9c7fd98e3bbe7f
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