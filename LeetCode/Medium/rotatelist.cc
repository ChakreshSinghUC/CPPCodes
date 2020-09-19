#include <iostream>
using namespace std;
//Definition for singly-linked list.
//This code wont work if S == lenght og linked list or 1.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        ListNode *last;
        ListNode *temp = head;
        int count = 0;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
            if (temp->next == NULL)
            {
                last = temp;
            }
        }

        if (k == count)
            return head;
        if (k > count)
            return NULL;
        int N = count - k;
        ListNode *save = head;
        while (N--)
        {
            save = save->next;
        }

        last->next = head;
        head = save->next;
        save->next = NULL;
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    Solution o;
    ListNode *root = o.rotateRight(head, k);
    while (root)
    {
        cout << root->val << "->";
        root = root->next;
    }
}