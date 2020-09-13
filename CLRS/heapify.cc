#include<iostream>
#include<vector>

using namespace std;

int t = 1;

void max_heap(vector<int> &arr, int i)
{
    int l, r, largest;
    l = 2*i; r = (2*i + 1);
    largest = i;
    //cout<<"L: "<<l<<"\t R:"<<r<<"\t i:"<<i<<endl;
    (arr[i] < arr[l] && l<arr.size()) ? largest = l : largest = i;
    if (arr[largest] < arr[r] && r<arr.size())  largest = r;
    if(largest != i) swap(arr[i], arr[largest]);
    /*int temp;     
    if(largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
    }*/
    if (largest< arr.size() && i!=largest) 
        max_heap(arr, largest);
    if(i<arr.size())
        max_heap(arr, ++t);

// arr.erase(arr.begin());
}

int main()
{
    //first element in the array is not used.
    vector<int> arr = {0, 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9};
    max_heap(arr, 1);
    for(int i : arr)
        cout<<i<<" ";
}
