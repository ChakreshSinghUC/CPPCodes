#include <iostream>
#include <map>

using namespace std;

int main() {

  string S = "AaAaCcBbbbbbb";

  // A-Z --> occurence count after balancing the pairs
  map<int, int> cnt;

//   int cnt[26] = {};
      // O(N)
      for (auto ch : S)
  {
      // Find: O(ln n)
    if (cnt.find(ch - 'A') == cnt.end() && ch >= 'A' && ch <= 'Z')
      {
          cnt[ch - 'A'] = 1;
      } else if (ch >= 'A' && ch <= 'Z') {
      cnt[ch - 'A']++;
    } else if (ch >= 'a' && ch <= 'z') {
      int idx = ch - 'a';
      if (cnt.find(idx) == cnt.end()) {
        cnt[ch - 'a'] = -1;
      } else {
        cnt[ch - 'a']--;
      }
    }
  }
  // second iteration
  string output;
  for (auto ch : S) {
    if (ch >= 'a' && ch <= 'z') {
      int idx = ch - 'a';
      if (cnt[idx] < 0) {
        output += ch;
        cnt[idx]++;
      }
    }

    if (ch >= 'A' && ch <= 'Z') {
      int idx = ch - 'A';
      if (cnt[idx] > 0) {
        output += ch;
        cnt[idx]--;
      }
    }
  }
  cout << output;
}

// Time Complexity:: O(N*log (K))
// N :: Size of the string
// K :: Size of the map