#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int start = 9;
    int end = 10;
    string p ;
    p = to_string(start) + "->" + to_string(end);
    cout << p << endl;
}