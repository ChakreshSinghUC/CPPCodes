// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> c{0};
        
        return c;
    }
};
int main()
{

    Solution obj;
    string s = "barfoothefoobarman";
    vector<string> words{"foo", "bar", "aaa"};

    vector<int> r;
    r = obj.findSubstring(s, words);

    for (auto t : r)
        cout << t << " ";
}