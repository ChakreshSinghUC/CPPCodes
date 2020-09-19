//https://code.google.com/codejam/contest/dashboard?c=3264486#s=p1
#include <iostream>
using namespace std;
bool istidy(long int N)
{
    int temp;
    while (N > 0)
    {
        temp = N % 10;
        N = N / 10;
        if (N % 10 > temp)
            return false;
    }
    return true;
}
int tidy(long int N)
{
    while (N > 0)
    {
        if (istidy(N))
            return N;
        N--;
    }
}
int main()
{
    long int T, N;
    cin >> T;
    int i = 1;
    while (T--)
    {
        cin >> N;
        cout << "Case #" << i << ": "  << tidy(N) << endl;
        i++;
    }
}
//works for small input for not for lare input given by Google