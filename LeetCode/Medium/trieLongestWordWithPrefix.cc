#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct trieNode
{
    unordered_map<char, trieNode *> next;
    bool flag = false;
};

class Solution {
    trieNode* head;
    string res;
public:
    string longestWord(vector<string>& words) {
        head = new trieNode();
        head->flag = true;
        for (string& word : words) {
            addWord(word);
        }
        dfs(head, "");
        return res;
    }
    
    void addWord(string& word) {
        trieNode* curr = head;
        for (char ch : word) {
            if (!(curr->next)[ch]) {
                (curr->next)[ch] = new trieNode();
            }
            curr = (curr->next)[ch];
        }
        curr->flag = true;
    }
    
    void dfs(trieNode* curr, string cache) {
        if (!curr->flag) return;

        if (cache.size() > res.size() || (cache.size() == res.size() && cache < res)) {
            res = cache;
        }
        
        for (auto p : (curr->next)) {
            dfs(p.second, cache + p.first);
        }
    }
};
int main()
{

}
