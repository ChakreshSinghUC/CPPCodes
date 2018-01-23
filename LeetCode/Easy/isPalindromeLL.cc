/**https://leetcode.com/problems/palindrome-linked-list/description/
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up: Could you do it in O(n) time and O(1) space?
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *temp = head;

        vector<int> vec1 = makeCopy(head);
        ListNode *t = reverseList(head);
        vector<int> vec2 = makeCopy(t);

        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i] != vec2[i])
                return false;
        }

        return true;
    }
    vector<int> makeCopy(ListNode *h)
    {
        vector<int> v;

        while (h)
        {
            v.push_back(h->val);
            h = h->next;
        }
        return v;
    }
    ListNode *reverseList(ListNode *rh)
    {
        ListNode *cursor = NULL;
        ListNode *next;
        while (rh)
        {
            next = rh->next;
            rh->next = cursor;
            cursor = rh;
            rh = next;
        }
        return cursor;
    }
};
int main()
{
    ListNode *head = NULL;
    ListNode *node = new ListNode(4);
    head = node;
    node->next = new ListNode(5);
    node->next->next = new ListNode(4);
    // node->next->next->next = new ListNode(4);

    Solution obj;
    cout << obj.isPalindrome(head);
}