// https://leetcode.com/problems/truncate-sentence/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string truncated_s;
        int count_words = 0;
        int i = 0;
        while (i < s.length() && count_words < k)
        {
            if (s[i] == ' ')
                count_words++;
            if (count_words < k)
                truncated_s += s[i];
            i++;
        }

        return truncated_s;
    }
};

int main()
{

    string s = "Hello how are you Contestant";
    int k = 4;
    Solution obj;
    cout << obj.truncateSentence(s, k);
}