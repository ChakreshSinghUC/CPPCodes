#include <iostream>
using namespace std;
int main()
{
    int nums = 8;
    int count_ones = 0;
    while (nums)
    {
        count_ones += nums & 1;
        nums >>= 1;
    }
    cout << count_ones << endl;

    nums = 8;

    count_ones = 0;
    while (nums)
    {
        count_ones += nums % 2;
        nums = nums / 2;
    }
    cout << count_ones;
}