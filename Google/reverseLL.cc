#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    int value;
    Node *nextptr;
    Node(int a, Node *p)
    {
        value = a;
        nextptr = p;
    }
};
void reverseLL(Node *head)
{
}
int main()
{
    Node *head = new Node(8, NULL);
    
}