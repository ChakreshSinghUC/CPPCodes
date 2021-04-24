#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int val;
    struct Node *next;

    Node(int data)
    {
        this->val = data;
        next = NULL;
    }
};

void print(struct Node *r)
{
    // Prints the Linked List

    struct Node *temp;
    cout << "\nPrinting all the nodes in the Linked List: \nroot\n|\n";
    temp = r;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void insertEnd(struct Node *r, int a)
{
    // Inserts a new node at the end of the Linked List

    cout << "\nInserting new Node to the Linked List\n\t";
    struct Node *temp, *prev;
    temp = r;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = new Node(a);
    cout << "... inserted " << a << " at the end. Sucsess!!!\n";
}

void insertStart(struct Node *&r, int a)
{
    cout << "\nInserting at root, value: " << a;
    struct Node *temp = new Node(a);
    temp->next = r;
    r = temp;
}
bool find(struct Node *r, int a)
{
    // Searches for a given value in the linked list
    int count = 0;
    if (r == NULL)
        return 0;

    while (r != NULL)
    {
        if (r->val == a)
        {
            cout << "\nSearch success!!! Found " << a << " at node index: " << count << "\n";
            return 1;
        }
        r = r->next;
        count++;
    }

    return 0;
}

void print_reverse(struct Node *r)
{
    if (!r)
        return;

    stack<int> s; 
    while (r)
    { 
        s.push(r->val);
        r = r->next;
    }
    cout << "\nThe Linked List in reverse order: \n";
    while (!s.empty())
    {
        cout << s.top() << " => ";
        s.pop();
    }
}
int main()
{
    // driver code
    struct Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    insertEnd(root, 5);
    int a = 4;
    if (!find(root, a))
        insertEnd(root, a);

    insertStart(root, 0);
    insertStart(root, -1);
    insertStart(root, -2);
    insertStart(root, -3);
    print(root);
    print_reverse(root);
    print(root);
}