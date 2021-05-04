// https://leetcode.com/problems/faulty-sensor/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int badSensor(vector<int> &sensor1, vector<int> &sensor2) {
    if (sensor1.size() == sensor2.size() && sensor1[0] != sensor2[0])
      return -1;

    int i = 0, j = 0;
    int temp_i, temp_j;

    while (sensor1[i] == sensor2[j] && i < sensor1.size() &&
           j < sensor2.size()) {
      i++;
      j++;
    }
    temp_i = i;
    temp_j = j;
    
    if ((i == sensor1.size() - 1 && j == sensor2.size() - 1) ||
        (i == sensor1.size() - 2 && j == sensor2.size() - 2))
      return -1;

    while (sensor1[i] == sensor2[j + 1]) {
      i++;
      j++;
      if (j + 1 == sensor2.size() - 1 && i == sensor1.size() - 1)
        return 1;
    }

    i = temp_i;
    j = temp_j;

    while (sensor1[i + 1] == sensor2[j]) {
      i++;
      j++;
      if (i + 1 == sensor1.size() - 1 && j == sensor2.size() - 1)
        return 2;
    }

    cout << i << "\t" << j << endl;
    return -1;
  }
};

int main() {
  //    [2,3,2,2,3,2]
  //    [2,3,2,3,2,7]
  vector<int> s1{2, 3, 2, 2, 3, 2};
  vector<int> s2{2, 3, 2, 3, 2, 7};

  Solution obj;
  cout << obj.badSensor(s1, s2);
}