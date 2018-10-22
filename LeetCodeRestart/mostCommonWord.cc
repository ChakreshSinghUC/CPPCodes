/*
ID: singhch1
LANG: C++11
TASK: test
*/

#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        vector<string> tokens;
        stringstream check1(paragraph);
        string intermediate;
        while (getline(check1, intermediate, ' '))
        {
            transform(intermediate.begin(), intermediate.end(), intermediate.begin(), ::tolower);
            tokens.push_back(intermediate);
        }
        for (int i = 0; i < tokens.size(); i++)
            cout << i << " " << tokens[i] << '\n';
        
        /*  map<string, int> m;
        int i = 0;
        int len = 0;
        // using transform() function and ::toupper in STL
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        cout << paragraph << endl;
        int l = 0;
        cout << paragraph.size() << endl;
        for (int i = 0; i < paragraph.size(); i++)
        {
            if (paragraph[i] == ' ' || paragraph[i] == '\0' || paragraph[i] == '.')
            {
                cout << paragraph.substr(l, i - l) << ", ";
                l = i + 1;
            }
            if (i == paragraph.size() - 1)
                cout << paragraph.substr(l, i - l + 1) << endl;
        }*/
        return "NULL";
    }
};
int main()
{
    string paragraph = "Bob, hit a ball, the hit BALL flew far after it was hit.";

    vector<string> banned = {"hit"};
    Solution obj;
    cout << obj.mostCommonWord(paragraph, banned);
    return 0;
}
