// https://leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *itr = head;
        vector<int> left, right;
        while (itr)
        {
            if (itr->val < x)
                left.push_back(itr->val);
            else
                right.push_back(itr->val);
            itr = itr->next;
        }
        ListNode *it = new ListNode(0);
        ListNode *h = it;

        for (int i = 0; i < left.size(); i++)
        {
            it->val = left[i];

            if (i != left.size() - 1)
            {
                it->next = new ListNode(0);
                it = it->next;
            }
            else
                it->next = new ListNode(right[0]);
        }
        for (int i = 1; i < right.size(); i++)
        {
            it->val = right[i];
            if (i != right.size() - 1)
            {
                it->next = new ListNode(0);
                it = it->next;
            }
        }
        return h;
    }
    ListNode *partition_incomplete(ListNode *head, int x)
    {
        ListNode *itr = head;
        ListNode *cur1 = nullptr, *cur2 = nullptr;
        ListNode *a, *b, *prev;

        while (itr)
        {
            if (itr->val < x)
            {
                if (cur1 == nullptr)
                    cur1 = itr;
                else
                    cur2 = itr;
                if (cur1 != nullptr && cur2 != nullptr)
                {
                    a = cur1->next;
                    b = cur2->next;

                    cur2->next = a;
                    cur1->next = cur2;

                    prev->next = b;

                    cur1 = cur2;
                    cur2 = nullptr;
                }
            }
            prev = itr;
            itr = itr->next;
        }
        return head;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);

    Solution obj;

    ListNode *h = obj.partition(head2, 2);

    while (h)
    {
        cout << h->val << "->";
        h = h->next;
    }
}