#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
  public:
 
    int numTrees(int n)
    {
        long C = 1;
        for (int i = 0; i < n; ++i)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
int main()
{
    Solution obj;
    int n = 18;
    cout << obj.numTrees(n);
}