#include <iostream>
using namespace std;
int result = 0; 
int recurr(int n) {
  cout << n << "\t" << result << "\n";
  if (n == 0){
    cout << "I am here!\n";
    return 1;
  }
  result++;
  recurr(n - 1);
  cout <<n<< "\tNow I am here!!\n";
  result++;
  return result;
}
int main() { cout << recurr(5); }