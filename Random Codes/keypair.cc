#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main() {
   int t;
  cin >> t;
  int size;
  int sum;
  while (t--) {
  map<int, int> kp;
  bool flag = false;
  cin >> size >> sum;
  int C[size];

  for (int i = 0; i < size; i++)
    {
        cin>>C[i];
        kp.insert(pair<int, int>(i, C[i]));
    }
  multimap<int, int>::iterator itr;
  multimap<int, int>::iterator itr2;
  for (itr = kp.begin(); itr != kp.end(); ++itr) {
    for (itr2 = kp.begin(); itr2 != kp.end(); ++itr2)
      if (itr2->second == sum - itr->second && itr2 != itr) {
        cout << itr->first << "\t" << itr2->first << endl;
        flag = true;
        break;
      }
    if (flag)
      break;
  }

  if (flag) {
    cout << "Yes";
  } else
    cout << "No";
}
}