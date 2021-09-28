// https://leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *h = head;
        ListNode *left_t = head;
        ListNode *right_t = head;

        if (left == right)
            return h;
        while (left < right)
        {
            ListNode *ptr = head;
            int count = 0;

            while (ptr)
            {
                if (count == left - 1)
                    left_t = ptr;

                if (count == right - 1)
                    right_t = ptr;

                count++;
                ptr = ptr->next;
            }

            if (left_t == nullptr || right_t == nullptr)
                return h;

            int temp = left_t->val;
            left_t->val = right_t->val;
            right_t->val = temp;

            left++;
            right--;
        }

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
    head->next->next->next->next->next = new ListNode(6);

    Solution obj;

    ListNode *p = head;
    while (p)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << endl;
    ListNode *r = obj.reverseBetween(head, 2, 5);
    while (r)
    {
        cout << r->val << "->";
        r = r->next;
    }
}
