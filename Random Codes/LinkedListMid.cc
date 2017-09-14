#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int data;
  Node *next;
};
int find_mid(Node *head) {

  vector<int> temp;

  Node ptr;

  ptr = *head->next;

  cout << ptr.data << endl;
  //   while (ptr != NULL) {
  //     temp.push_back(ptr->data);
  //     ptr = ptr->next;
  return -1;
}

int main() {
  Node *head;
  head = new Node;

  Node ptr;

  ptr.data = 3;
  ptr.next = NULL;

  *head->next = ptr;

  cout << find_mid(head);
}