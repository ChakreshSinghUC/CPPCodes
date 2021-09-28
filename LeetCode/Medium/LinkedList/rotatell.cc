
#include <iostream>
#include <vector>

using namespace std;

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        ListNode *h = head;
        ListNode *h1 = head;
        ListNode *last;
        int count = 0;

        while (head)
        {
            count++;
            if (head->next == nullptr)
                last = head;
            head = head->next;
        }
        last->next = head;
        int _k = k % count;
        int t = count - _k;
        while (t--)
        {
            h1 = h1->next;

        }
        h = h1;
        return h;
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

    Solution obj;
    ListNode *h = obj.rotateRight(head, k);

    while (h)
    {
        cout << h->val << "->";
        h = h->next;
    }
}