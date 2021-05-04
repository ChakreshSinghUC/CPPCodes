#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> elem;
    for (int i = 0; i < 10; i++)
        elem.push_back(i);
    // elem.pop_front();
    // elem.pop_back();

    for (auto i : elem)
        cout << i << ", ";
}
