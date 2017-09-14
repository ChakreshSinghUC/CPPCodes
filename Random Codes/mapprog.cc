#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long temp = n;
  map<string, long long> m;
  string name;
  long long phone;

  while (n--) {
    cin >> name;
    cin >> phone;
    m[name] = phone;
  }

  n = temp;
  string s;
  vector<string> vec;
  while (n--) {

    cin >> s;
    vec.push_back(s);
  }

  n = temp;
  long long i = 0;
  while (n--) {
    map<string, long long>::iterator itr = m.find(vec[i]);
    if (itr != m.end())
      cout << itr->first << "=" << itr->second << endl;
    else
      cout << "Not found\n";

    i++;
  }

  return 0;
}
