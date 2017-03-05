/*
K largest(or smallest) elements in an array | added Min Heap method
Question: Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.

For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A[] = {1, 23, 12, 9, 30, 2, 50};
    int k;
    int size = sizeof(A) / sizeof(A[0]);

    sort(A, A + size);

    cout << "\nEnter K: ";
    cin >> k;

    for (int i = size - 1; i >= (size - k); i--)
    {
        cout << endl
             << A[i] << endl;
    }

    return -1;
}