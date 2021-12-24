#include <iostream>
#include <memory>


using namespace std;

class MyLinkedList {
  int size;
  struct Node {
    int val;
    Node *next;
    Node(int a) {
      val = a;
      next = nullptr;
    }
  };
  Node *head = new Node(0);

public:
  

  MyLinkedList()
  {
    size = 0;
    delete head->next;
  }

  int get(int index) {
    if (index > size - 1)
      return -1;

    Node *ptr = head->next;
    while (index--) {
      ptr = ptr->next;
    }

    return ptr->val;
  }

  void addAtHead(int val) {
    size++;
    Node *ptr = new Node(val);
    ptr->next = head->next;
    head->next = ptr;
  }

  void addAtTail(int val) {
    size++;
    Node *ptr = new Node(val);
    Node *itr = head;
    while (itr->next != nullptr) {
      itr = itr->next;
    }
    itr->next = ptr;
  }

  void addAtIndex(int index, int val) {
    if (index > size)
      return;
    Node *ptr = new Node(val);
    Node *itr = head;
    Node *itrnext;
    while (index--) {
      itr = itr->next;
      itrnext = itr->next;
    }

    if (itr == nullptr)
      return;

    itr->next = ptr;
    ptr->next = itrnext;

    size++;
  }

  void deleteAtIndex(int index) {
    if (index > size - 1)
      return;
    Node *itr = head->next;
    Node *prev = head;
    while (index--) {
      prev = itr;
      itr = itr->next;
    }
    if (itr == nullptr)
      return;
    prev->next = itr->next;
    delete itr;
    size--;
  }
  void print_linked_list() {
    Node *ptr = head;
    while (ptr) {
      cout << ptr->val << "->";
      ptr = ptr->next;
    }
    cout << "\n";
  }
};

int main() {
    MyLinkedList obj;

    //   [
    //     "MyLinkedList", "addAtHead", "addAtHead", "addAtHead",
    //     "addAtIndex", "deleteAtIndex", "addAtHead", "addAtTail", "get",
    //     "addAtHead", "addAtIndex", "addAtHead"
    //   ][[], [7], [2], [1], [ 3, 0 ], [2], [6], [4], [4], [4],
    //     [ 5, 0 ], [6]] MyLinkedList obj;

    obj.addAtHead(2); 
    obj.addAtIndex(0, 1);

    obj.print_linked_list();

     
   cout<<": "<<  obj.get(1); 
}
