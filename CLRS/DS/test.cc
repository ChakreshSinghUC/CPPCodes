#include <iostream>

using namespace std;
template <typename T> 

void _swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
    int a = 5;
    int b = 4;
    if (a > b)
    {
        cout << "ok " << endl;
        _swap(a, b);
        //_bubbleUp(p);
    }
    else
        cout << "no " << endl;
    // My swap function

    cout << a << "\t" << b << endl;
}