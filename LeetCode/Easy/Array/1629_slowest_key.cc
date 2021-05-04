// https://leetcode.com/problems/slowest-key/

#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    char slowest_key = keysPressed[0];
    if (releaseTimes.size() == 1)
      return keysPressed[0];
    int max_time = releaseTimes[0];
    for (int i = 1; i < releaseTimes.size(); i++) {
      if (max_time <= releaseTimes[i] - releaseTimes[i - 1]) {

        if (max_time == releaseTimes[i] - releaseTimes[i - 1] &&
            slowest_key < keysPressed[i])
          slowest_key = keysPressed[i];

        else if (max_time == releaseTimes[i] - releaseTimes[i - 1] &&
                 slowest_key > keysPressed[i])
          ;
        else if (max_time < releaseTimes[i] - releaseTimes[i - 1])
          slowest_key = keysPressed[i];
      }
      cout << keysPressed[i] << "\t" << max_time << "\t"
           << releaseTimes[i] - releaseTimes[i - 1] << endl;
    }
    return slowest_key;
  }
};

int main() {
  // [12,23,36,46,62]
  // "spuda"
  vector<int> releaseTimes{28, 65, 97};
  string keysPressed = "gaf";
  Solution obj;
  cout << obj.slowestKey(releaseTimes, keysPressed);
}