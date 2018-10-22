#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node{int val;
Node* next;
};
void initNode(struct Node *head, int n) {
  head->val = n;
  head->next = NULL;
}
void addNode(struct Node *head, int n) {
  struct Node *NewNode = new Node;
  NewNode->val = n;
  NewNode->next = head;
  head = NewNode;
}
class Solution {
public:
  int numComponents(Node *head, vector<int> &G) {
      cout<<"here";
      Node *temp;
      temp = head;
      int count =0;
      while(temp->next != NULL){
          cout<<temp->val<<"\t"<<temp->next->val<<endl;
        if (find(G.begin(), G.end(), temp->val) != G.end() &&
            find(G.begin(), G.end(), temp->next->val) != G.end())
            count++;

          temp = temp->next;
      }
      return count;
  }
};
int main() {
    vector<int> G = {0,1,3};
    Node *head;
    initNode(head,3);
    addNode(head,2);
    addNode(head,1);
    addNode(head,0);
    Node *temp;
    temp = head;
    int count = 0;
    while (temp->next != NULL) {
      cout << temp->val << "\t" << temp->next->val << endl;
      temp=temp->next;
    }
      Solution obj;
      cout << "1";
      cout << "Count: " << obj.numComponents(head, G);
}