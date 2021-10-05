#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int k = 0;
    while (T--)
    {
        int N;
        cin >> N;
        float A[N];
        int m;
        for (int i = 0; i < N; i++)
        
        {
            cin>>A[i];
        }
        k++;
        
        //   double A[] = {2, 4, 8, 16, 32, 64}; //{1, 1, 1};
        //  int N = sizeof(A) / sizeof(A[0]);
        // cout << N << endl;
      long long int count = 0;
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = i + 1; j < N - 1; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    if (A[k] == A[i] * A[j] || A[k] == A[i] / A[j] || A[k] == A[j] / A[i])
                    {
                        count++;
                        // cout << i << ", " << j << ", " << k << " :" << count << endl;
                    }
                }
            }
        }
        cout << "Case #" << k << ": " << count<<endl;
       
    }
}