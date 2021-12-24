// Linked List basics
#include <forward_list>
#include<iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int a) {
    val = a;
    next = nullptr;
  }
};

class Solution {
public:
  void add_node(Node *root, int a) {
    while (root->next != nullptr) {
      root = root->next;
    }
    root->next = new Node(a);
  }

  void display_ll(Node *r) {
    cout << "\nPrinting the linked list: \n";
    while (r != nullptr) {
      cout << r->val << "->";
      r = r->next;
    }
  }
  void reverse_ll(Node *&root) {
    // Initialize current, previous and next pointers
    Node *current = root;
    Node *prev = nullptr, *next = nullptr;
    while (current != nullptr) {
      // Store next
      next = current->next;
      // Reverse current node's pointer
      current->next = prev;
      // Move pointers one position ahead.
      prev = current;
      current = next;
    }
    root = prev;
  }
  bool find(Node *root, int a) {
    while (root != nullptr) {
      if (root->val == a) {
        return true;
      }
      root = root->next;
    }
    return false;
  }
  void push_front_ll(Node* &root, int a){
    Node *ptr = new Node(a);
    ptr->next = root;
    root = ptr;
  }
};
int main() {

  Solution obj;
  Node *root = new Node(0);
  for (int i = 1; i < 10; i++) {
    obj.add_node(root, i);
  }

  obj.push_front_ll(root, 10);
  obj.display_ll(root);
  obj.reverse_ll(root);
  obj.display_ll(root);

  cout << endl;

  std::forward_list<int> l;
  l.push_front(6);
  l.push_front(5);
  for(auto i: l)
      cout << i << "->";
 }