#include <bits/stdc++.h>
using namespace std;

/* Function to check if x is power of 2*/
bool isPowerOfTwo(int x)
{
    // cout<<!(x & (x - 1));
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

/*Driver program to test above function*/
int main()
{
    isPowerOfTwo(0) ? cout << "Yes\n" : cout << "No\n";
    isPowerOfTwo(64) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}