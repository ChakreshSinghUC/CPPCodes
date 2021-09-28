#include<iostream>
using namespace std;

int main()
{
    cout<<"Hello there!!!\n";
    int a = 5;
    int *b;
    b= &a;

    cout<<"Pointer to integer variable a: "<<b;
    cout<<"\nValue at pointer to integer variable a: "<<*b;

}  