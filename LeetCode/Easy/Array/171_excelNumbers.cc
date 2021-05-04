#include <iostream>
#include <map>
#include <vector>
#include<math.h>

using namespace std;

class Solution {
public:
  int titleToNumber(string columnTitle) {
    int converted = 0;
    
    map<char, int> mymap;
    for (int i = 0; i < 26; i++)
      mymap['A' + i]= i+1;

    int k = columnTitle.length();

    int i = 0;
    while (k>=0) {

    //   cout << columnTitle[k]<<"\t"<<mymap[columnTitle[k]] << endl;
      converted += mymap[columnTitle[k]] * pow(26, i);
      i++;
      k--;
    }
    return converted;
  }
};

int main() {

  Solution obj;
  cout << obj.titleToNumber("AAAB");
}