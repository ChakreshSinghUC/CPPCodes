// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <iostream>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (!head)
            return head;

        ListNode *ptr = head;

        while (ptr->next)
        {

            if (ptr->next)
            {
                while (ptr->val == ptr->next->val)
                {

                    ListNode *delNode = ptr->next;
                    cout << "ptr: " << ptr->val << "\t"
                         << "Next: " << ptr->next->val << "\t"
                         << "Delete: " << delNode->val << "\n";
                    if (ptr->next->next == NULL)
                    {
                        ptr->next=NULL;
                        delete (delNode);
                        return head;
                    }
                    ptr->next = ptr->next->next;
                    delete (delNode); //free the deleted node space.
                }
            }
            ptr = ptr->next;
        }

        return head;
    }
};

void printLinkedList(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }

    cout << "\n";
}
int main()
{

    Solution obj;
    ListNode *Head = new ListNode(1);
    Head->next = new ListNode(1);
    Head->next->next = new ListNode(1); 

    printLinkedList(Head);
    obj.deleteDuplicates(Head);
    printLinkedList(Head);
}