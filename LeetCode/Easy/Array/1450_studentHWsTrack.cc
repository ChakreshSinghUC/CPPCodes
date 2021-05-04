// https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
// Return the number of students doing their homework at time queryTime. More
// formally, return the number of students where queryTime lays in the interval
// [startTime[i], endTime[i]] inclusive.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int count_students = 0;
    for (int i = 0; i<startTime.size(); i++)
    {
        if(startTime[i]<= queryTime && queryTime<=endTime[i])
          count_students++;
    }
      return count_students;
  }
};
int main() {
  Solution obj;
  vector<int> startTime{9,8,7,6,5,4,3,2,1};
  vector<int> endTime{10,10,10,10,10,10,10,10,10};
  int queryTime = 5;
  cout << obj.busyStudent(startTime, endTime, queryTime);
}