//https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>

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

int main()
{

    ListNode* L1 = new ListNode(6);
    ListNode* L2 = new ListNode(5, L1);
    ListNode* L3 = new ListNode(4, L2);

    ListNode* L = L3;

    ListNode* P1 = new ListNode(7);
    ListNode* P2 = new ListNode(5, P1);
    ListNode* P3 = new ListNode(1, P2);


    ListNode* P = P3;

    while(L!=nullptr)
    {
        cout<<L->val<<"->";
        L=L->next;
    }
    
    
    cout<<"Null \n";


    while(P!=nullptr)
    {
        cout<<P->val<<"->";
        P=P->next;
    }
    cout<<"Null \n"; 
    
    ListNode* L_ = L3;
    ListNode* P_ = P3;

    ListNode* ans;
    ListNode* t = ans;

    while(L_ != nullptr && P_ != nullptr){
        if (L_->val < P_->val){ 
            ans->val = L_->val; 
            L_= L_->next;
            }
        else {
            ans->val = P_->val;
            P_=P_->next;
            }
        ans = ans->next;
    }
    if(L_ == nullptr && P_ != nullptr){
        ans->val = P_->val;
        ans = ans->next;
        P_ = P_->next;
        }

        if(P_ == nullptr && L_ != nullptr){
        ans->val = L_->val;
        ans = ans->next;
        L_ = L_->next;
        }
    while(t != nullptr)
    {
        cout<<t->val<<"->";
        t=t->next;
    }
}