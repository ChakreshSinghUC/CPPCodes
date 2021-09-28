
// https://leetcode.com/problems/word-ladder-ii/

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog" 

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
    bool isNeighbour(string s, string p) {

        int c = 0;
        if ((int)s.length() != (int)p.length())
            return false;

        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] != p[i])
                c++;
            if (c > 1)
                return false;
            }
        return true;
        };
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        return { {} };
        }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if (isNeighbour(beginWord, endWord))
            return 2;

        int n = (int)wordList.size();
        map<string, bool> visited;

        vector<vector<string>> connectedwords;

        for (int i = 0; i < n; i++)
            {
            vector<string> val;
            for (int j = 0; j < n;j++)
                {
                if (isNeighbour(wordList[i], wordList[j]))
                    val.push_back(wordList[j]);
                }
            connectedwords.push_back(val);
            }

        queue<string> q;
        q.push(beginWord);
        int min_length = INT_MAX;
        int count = 1;
        while (!q.empty())
            {
            string s = q.front();
            cout << s << "->";
            visited[s] = true;
            q.pop();
            for (int i = 0; i < (int)connectedwords.size(); i++)
                {
                for (int j = 0; j < (int)connectedwords[0].size(); j++) {
                    if (isNeighbour(connectedwords[i][j], s) && !visited[connectedwords[i][j]])
                        {
                        count++;
                        if (connectedwords[i][j] == endWord)
                            {
                            cout << endWord << endl;
                            min_length = min(count, min_length);
                            count = 1;
                            }
                        q.push(connectedwords[i][j]);
                        visited[connectedwords[i][j]] = true;
                        }
                    }
                }
            }
        return min_length;
        }

    bool isReachable(string beginWord, string endWord, vector<string>& wordList) {
        //Checks if endWord is rechable from beginWord

        bool flag = false;
        int n = (int)wordList.size();
        map<string, bool> visited;

        for (auto w : wordList)
            {
            if (w == beginWord)
                flag = true;

            visited[w] = false;
            }
        if (!flag)
            return false;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
            {
            string s = q.front();
            visited[s] = true;

            q.pop();
            for (auto w : wordList) {
                if (isNeighbour(w, s) && !visited[w])
                    {

                    if (w == endWord)
                        return true;
                    q.push(w);
                    visited[w] = true;
                    }
                }
            }
        return false;
        }
    };
int main()
    {
    vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
    string beginWord = "hit", endWord = "cog";
    Solution o;
    cout << o.ladderLength(beginWord, endWord, wordList);
    }