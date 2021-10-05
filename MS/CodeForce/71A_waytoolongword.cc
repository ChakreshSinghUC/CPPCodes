// https://codeforces.com/problemset/problem/71/A

#include<iostream>
using namespace std;

class Sol {
    public: 
        int distance(string a, string b) {
        int diff = 0;
        cout << "here";
        for (int i = 0; i < a.length(); i++)
            {
            cout << a[i] << "\t" << b[i] << endl;
            if (a[i] != b[i])
                {
                cout << a[i] << "\t" << b[i] << endl;
                diff++;
                }
            }
        return diff;
        }
    };
int main()
    {
    Sol o;
    cout << o.distance("chak", "chik");
    
    // int n;
    // cin >> n;
    // while (n--) {
    //     string a;
    //     cin >> a;
    //     if (a.length() > 10)
    //         cout << a[0] + to_string(a.length() - 2) + a[a.length() - 1] << endl;
    //     else
    //         cout << a << endl;
    //     }
    }
