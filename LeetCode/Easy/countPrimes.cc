#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        const double size = floor(0.5 * (n - 3)) + 1;
        cout << 2 << ", ";
        int count = 0;
        deque<bool> is_prime(size, true);
        for (long i = 0; i < size; ++i)
        {
            if (is_prime[i])
            {

                long p = (i * 2) + 3;
                cout << p << ", ";
                count++;

                for (long j = (i * i) * 2 + 6 * i + 3; j < size; j += p)
                {
                    is_prime[j] = false;
                }
            }
        }
        cout << endl;
        return count;
    }
};
int main()
{

    Solution o;
    cout << o.countPrimes(10);
}