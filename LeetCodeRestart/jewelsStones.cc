#include <iostream>
#include <set>
using namespace std;
class Solution
{
  public:
    int numJewelsInStones(string J, string S)
    {

        set<char> j_set;
        int count_jewels = 0;
        for (int i = 0; i < J.size(); i++)
            j_set.insert(J[i]);//make a set of all the morse codes. 

        for (int i = 0; i < S.size(); i++)
        {
            auto it = j_set.find(S[i]);
            if (it != j_set.end())
                count_jewels++;
        }
        return count_jewels;
    }
};
int main()
{
    Solution obj;
    string J = "aA";
    string S = "aAAbbbb";
    cout << obj.numJewelsInStones(J, S);
}