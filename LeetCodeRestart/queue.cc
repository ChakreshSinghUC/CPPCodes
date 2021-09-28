#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(9);
    q.push(11);
    
    while (!q.empty())
    {
        cout << q.front()<<", ";
        q.pop();
    }
}