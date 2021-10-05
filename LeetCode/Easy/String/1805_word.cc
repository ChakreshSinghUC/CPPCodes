// https://leetcode.com/problems/number-of-different-integers-in-a-string/

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {

        set<int> number_counter;
        int temp = 0;
        bool updated = 0;
        int i = 0;

        while (i < word.length())
        {
            if (word[i] - '0' >= 0 && word[i] - '0' <= 9)
            {
                temp += temp * 10 + (word[i] - '0');
                updated = 1;
            } 
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                if (updated)
                    number_counter.insert(temp);
                temp = 0;
                updated = 0;
                word[i] = ' ';
            }
            i++;
        }
        if (updated)
            number_counter.insert(temp);

        return number_counter.size();
    }
};

int main()
{

    string word = "0aaa";
    Solution obj;
    cout << obj.numDifferentIntegers(word);
}