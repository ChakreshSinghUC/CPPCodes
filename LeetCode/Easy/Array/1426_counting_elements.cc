// https://leetcode.com/problems/counting-elements/

#include <iostream>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
  int countElements(vector<int> &arr) {
    //   Given an integer array arr, count how many elements x there are, such
    //   that x + 1 is also in arr. If there are duplicates in arr, count them
    //   separately.

    int count_elements = 0;
    set<int> s;
    for (int i = 0; i < arr.size(); i++) {
      s.insert(arr[i]);
    }

    // copy(
  
    //     // From point of the destination
    //     s.begin(),
  
    //     // From point of the destination
    //     s.end(),
  
    //     // Method of copying
    //     back_inserter(arr));
  

    for (int i = 0; i < arr.size(); i++) {
      if (s.find(arr[i] + 1) != s.end())
        count_elements++;
    }

    return count_elements;
  }
};
int main() {
  vector<int> arr{1,3,2,3,5,0};

  Solution obj;
  cout << obj.countElements(arr);
}