// https://leetcode.com/problems/longest-string-chain/

// Given a list of words, each word consists of English lowercase letters.

// Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to
// word2. For example, "abc" is a predecessor of "abac".

// A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2,
// word_2 is a predecessor of word_3, and so on.

// Return the longest possible length of a word chain with words chosen from the given list of words.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPredecesor(string w1, string w2)
    { //return true if adding one letter in w1 makes it same as w2

        if (w2.length() - w1.length() != 1)
            return 0;
        int j = 0;
        int count_match = 0;
        for (int i = 0; i < w2.length(); i++)
        {
            if (j == w1.length())
                break;
            if (w1[j] == w2[i])
            {
                j++;
            }
        }
        return (j == w2.length() - 1);
    }
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const std::string &first, const std::string &second) {
            return first.size() < second.size();
        });
        int n = words.size();
        vector<int> predecesor(n, 1);
        int max_word_chain = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecesor(words[j], words[i]))
                    predecesor[i] = max(predecesor[i], 1 + predecesor[j]);
            }
            max_word_chain = max(max_word_chain, predecesor[i]);
        }

        return max_word_chain;
    }
};

int main()
{
    vector<string> words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    Solution o;
    cout << o.longestStrChain(words);
}
