#include <iostream>
using namespace std;
void convertToBinary(unsigned int n)
{
    if (n / 6 != 0)
    {
        convertToBinary(n / 6);
    }
    cout << n % 6;
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        convertToBinary(n);
        cout << endl;
    }
}
