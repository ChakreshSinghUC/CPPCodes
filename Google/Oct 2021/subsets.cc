#include <iostream>
#include <vector>

using namespace std;

class perms
{
    vector<int> permutation;
    int n = 5;
    vector<bool> chosen (n, false);

public:
    void subsets()
    {
        vector<vector<int>> subsets;
        int n = 5;
        for (int b = 0; b < (1 << n); b++)
        {
            vector<int> subset;
            for (int i = 0; i < n; i++)
            {
                if (b & (1 << i))
                    subset.push_back(i);
            }
            subsets.push_back(subset);
        }

        for (int i = 0; i < subsets.size(); i++)
        {
            for (int j = 0; j < subsets[i].size(); j++)
                cout << subsets[i][j] << ", ";
            cout << endl;
        }
    }

    void search()
    {

        if (permutation.size() == n - 1)
        {
            for (auto p : permutation)
                cout << p << ", ";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (chosen[i])
                    continue;
                chosen[i] = true;
                permutation.push_back(i);
                search();
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
};
int main()
{
    perms o;
    o.search();
}