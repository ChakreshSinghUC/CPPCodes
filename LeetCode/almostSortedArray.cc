// if there is a sorted array with two numbers swapped with each other, find them..
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr{1, 2, 3, 8, 5, 6, 7, 4, 9};
    int x = -1, y = -1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            y = arr[i + 1];
            if (x == -1)
                x = arr[i];
            else
                break; //if you found the pair x and y, no need to look further.
        }
    }

    cout << x << "\t" << y;
}