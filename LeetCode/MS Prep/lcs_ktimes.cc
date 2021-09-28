// https://leetcode.com/problems/longest-subsequence-repeated-k-times/
// You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
// Constraints:

// n == s.length
// 2 <= k <= 2000
// 2 <= n < k * 8
// s consists of lowercase English letters.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool check(string& s, string& p, int k) {
        // check to see if new_cur is repeated k times.
        for (int i = 0, j = 0; i < s.size() && k > 0; ++i) {
            j += p[j] == s[i];
            if (j == p.size()) {
                --k;
                j = 0;
                }
            }
        return k == 0;
        }
    void generate(string& s, string& chars, string& cur, string& best, int mask, int k) {
        for (int i = 0; i < chars.size(); ++i) {
            if ((mask & (1 << i)) == 0) {
                string new_cur = cur + chars[i];
                cout << "new_cur: " << new_cur << endl;
                if (check(s, new_cur, k)) {
                    if (new_cur.size() > best.size())
                        best = new_cur;
                    generate(s, chars, new_cur, best, mask + (1 << i), k);
                    }
                }
            }
        }
    string longestSubsequenceRepeatedK(string& s, int k) {
        int cnt[26] = {};
        string chars, best;
        for (auto ch : s)
            ++cnt[ch - 'a'];
        for (int i = 25; i >= 0; --i)
            chars += string(cnt[i] / k, 'a' + i);
        cout << "chars: " << chars << endl;
        generate(s, chars, string() = {}, best, 0, k);
        return best;
        }
    };

int main()
    {
    string s = "letsleetcode";
    int k = 2;
    Solution o;
    cout << o.longestSubsequenceRepeatedK(s, k);
    }