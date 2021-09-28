#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
   public:
   int ok(double x, vector <int>& v){
      int ret = 0;
      for (int i = 0; i < v.size() - 1; i++) {
         ret += ceil((v[i + 1] - v[i]) / x) - 1;
      }
      return ret;
   }
   double minmaxGasDist(vector<int>& s, int K) {
      double low = 0;
      int n = s.size();
      double high = s[n - 1] - s[0];
      while (high - low >= 1e-6) {
         double mid = (low + high) / 2.0;
         int x = ok(mid, s);
         if (x > K) {
            low = mid;
         }
         else {
            high = mid;
         }
      }
      return high;
   }
};
int main(){
   Solution ob;
   vector<int> v = {1,2,3,4,5,6,7,8,9,10};
   cout << (ob.minmaxGasDist(v, 9));
}