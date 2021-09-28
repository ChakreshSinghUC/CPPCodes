#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
    {
    priority_queue<int> pq; 
    vector<int> vec; 
    for (int i = 10; i >=0; i--)
        {
        vec.push_back(i);
        // stk.push(i);
        }
    // stk.pop(); 


    pq.insert(10);
    pq.insert(0);
    pq.insert(100);

    cout << pq.top();

    sort(vec.begin(), vec.end());
    // for (auto a : vec)
    //     {
    //     cout << a << endl;
    //     }


    // for (int i = 0; i < 10; i++)
    //     cout << vec[i] << "\t";
    }