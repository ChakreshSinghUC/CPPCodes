// https://leetcode.com/problems/high-five/
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > highFive(vector<vector<int> > &items) {
    vector<vector<int> > results;
    map<int, vector<int> > my_map;
    for (int i = 0; i < items.size(); i++) {
      my_map[items[i][0]].push_back(items[i][1]);
    }
    for (auto const &it : my_map) {

      vector<int> temp;
      vector<int> r;
      //   sort(it.second.begin(), it.second.end());
      for (auto a : it.second)
        temp.push_back(a);

      sort(temp.begin(), temp.end(), greater<int>());
      int high_five_score = 0;
      for (int i = 0; i < 5; i++) {
        // cout << temp[i] << ",";
        high_five_score += temp[i];
      }

      //   cout << it.first << " :  avg_high_five_score:" << high_five_score / 5
      //        << endl;
      r.push_back(it.first);
      r.push_back(high_five_score / 5);
      results.push_back(r);
    }
    return results;
  }
};

int main() {
  vector<vector<int> > items{{1, 91},  {1, 92},  {2, 93}, {2, 97},
                             {1, 60},  {2, 77},  {1, 65}, {1, 87},
                             {1, 100}, {2, 100}, {2, 76}};
  Solution obj;

  obj.highFive(items);
}