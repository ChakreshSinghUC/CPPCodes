
#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

class list_concurrent {

  struct node {
    // mutex m;
    int data;
    unique_ptr<node> next{nullptr};
    node(int a) {
      data = a;
      unique_ptr<node> next{nullptr};
    }
  };

  unique_ptr<node> head{make_unique<node>(0)};

public:
  list_concurrent() {}
  ~list_concurrent() {}

  void push_front(int val) {
    unique_ptr<node> new_node(make_unique<node>(val));
    new_node->next = move(head->next);
    head->next = move(new_node);
  }

  void print_list() {
    auto t = move(head);
    cout << "***Printing***\n";
    while (t->next != nullptr) {
      cout << t->data << "->";
      t = move(t->next);
    }
  }
};

int main() {
  list_concurrent o;
  o.push_front(1);
  o.push_front(2);
  o.push_front(3);
  o.push_front(4);
  o.push_front(5);
  o.print_list(); 
}