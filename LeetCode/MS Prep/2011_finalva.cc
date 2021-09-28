#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
         set<string> inc = {"++X", "X++"};
         set<string> dec = {"--X", "X--"};

        int x = 0;
        
        for(auto a: operations)
        {
            if(inc.find(a)!=inc.end())
                x++;
            else if(dec.find(a)!=dec.end())
                x--;
        }
        return x;
    }
    };

int main()
    {
    vector<string>  operations = {"--X", "X++", "X++"};
    Solution obj;
    cout<<obj.finalValueAfterOperations(operations);
    } 