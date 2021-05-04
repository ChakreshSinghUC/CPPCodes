// https://leetcode.com/problems/single-row-keyboard/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        map<char, int> my_keyboard;
        int time = 0;
        for (int i = 0; i < keyboard.length(); i++)
            my_keyboard.insert(pair<char, int>(char(keyboard[i]), i));

        int prev = 0;
        for (int i = 0; i < word.length(); i++)
        {
            time += abs(prev - my_keyboard.find(word[i])->second);
            prev = my_keyboard.find(word[i])->second;
        }

        return time;
    }
};
int main()
{
    string keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode";
    Solution obj; 
    cout << obj.calculateTime(keyboard, word);
}