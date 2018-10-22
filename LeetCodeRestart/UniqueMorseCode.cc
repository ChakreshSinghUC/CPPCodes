//https://leetcode.com/problems/unique-morse-code-words/description/
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse_codes = {".-",
                                      "-...",
                                      "-.-.",
                                      "-..",
                                      ".",
                                      "..-.",
                                      "--.",
                                      "....",
                                      "..",
                                      ".---",
                                      "-.-",
                                      ".-..",
                                      "--",
                                      "-.",
                                      "---",
                                      ".--.",
                                      "--.-",
                                      ".-.",
                                      "...",
                                      "-",
                                      "..-",
                                      "...-",
                                      ".--",
                                      "-..-",
                                      "-.--",
                                      "--.."};
        map<char, string> m;
        int j = 0;
        for (auto i : morse_codes)
        {
            m.insert(pair<char, string>('a' + j, i));
            j++;
        }
        set<string> code;

        for (auto a : words)
        {
            string w = a;
            string w_code;
            for (int i = 0; i < w.size(); i++)
            {
                auto it = m.find(w[i]);
                w_code += it->second;
            }
            code.insert(w_code);
        }
        return code.size();
    }
};
int main()
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution obj;
    cout << obj.uniqueMorseRepresentations(words);
}