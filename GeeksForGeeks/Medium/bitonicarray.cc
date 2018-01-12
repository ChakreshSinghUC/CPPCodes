#include <iostream>
using namespace std;
bool bitonic(int A[], int l, int r)
{
    int l_max = 0;
    int l_min = 0;
    bool flag = false;
    for (int i = l + 1; i <= r - 1; i++)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
            l_max++;
        if (A[i - 1] > A[i] && A[i] < A[i + 1])
            l_min++;
    }

    if (l_max < 2 && l_min == 0)
        flag = true;

    return flag;
}
int arraysum(int A[], int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
        sum += A[i];
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;

        int A[size];
        for (int i = 0; i < size; i++)
            cin >> A[i];

        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (bitonic(A, i, j))
                    sum = max(sum, arraysum(A, i, j));
            }
        }
        cout << sum << endl;
    }
}
