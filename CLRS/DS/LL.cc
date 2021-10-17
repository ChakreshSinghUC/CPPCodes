#include <iostream>

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
};
int main() {

  Solution obj;
  Node *root = new Node(0);
  for (int i = 1; i < 10; i++) {
    obj.add_node(root, i);
  }
  obj.display_ll(root);
  obj.reverse_ll(root);
  obj.display_ll(root);

  cout << "\nFound 5? ";

  if (obj.find(root, 5))
    cout << "Yes!";
  else
    cout << "Sorry";
}