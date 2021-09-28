//https://code.google.com/codejam/contest/dashboard?c=3264486#s=p0
#include <iostream>
using namespace std;
int flipToHappy(string s, int k)
{
    int len = s.length();
    int l = 0;
    int count = 0;
    while (l < len - k + 1)
    {
        if (s[l] == '-')
        {
            for (int i = 0; i < k; i++)
                (s[l + i] == '+') ? s[l + i] = '-' : s[l + i] = '+';
            count++;
        }
        l++;
    }
    for (int i = 0; i < len; i++)
        if (s[i] == '-')
        {
            count = -1;
            return count;
        }
    return count;
}
int main()
{
    int T;
    cin >> T;
    string S;
    int K;

    int caseNumber = 1;
    while (T--)
    {
        cin >> S >> K;
        cout << "Case #" << caseNumber << ": ";
        if (flipToHappy(S, K) == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << flipToHappy(S, K) << endl;
        caseNumber++;
    }
}