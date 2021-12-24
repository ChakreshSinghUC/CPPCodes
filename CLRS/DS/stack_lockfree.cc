
#include <iostream>
template <typename T>
class Solution {
private:
  struct Node {
    T data;
    Node *next;
    Node(T const &_data) : data(_data) {}
  };

 std::atomic<Node *> head;

public: 
    void push(T const &data)
    {
        Node *const new_node = new Node(data);
        new_node->next = head.load();
        while (!head.compare_exchange_weak(new_node->next, new_node))
            ;
    }
};
int main() {
  Solution obj;
  obj.push(5);
 }


//  {
//    "resource" : "/Users/grace/Desktop/CPPCodes/CLRS/DS/stack_lockfree.cc",
//                 "owner" : "clang",
//                           "severity" : 8,
//                           "message"
//        : "no viable constructor or deduction guide for deduction of template "
//          "arguments of 'Solution'",
//          "startLineNumber" : 25,
//          "startColumn" : 12,
//          "endLineNumber" : 25,
//          "endColumn" : 12
//  }

  // 6258521
  // 211391825

  //    L Once you have the payoff,
  //    you can wire the funds to your Savings account using your member number and
  //        DCU's routing number, 211391825 or mail us a check. L The address is
  //            Digital Federal Credit Union,
  //    220 Donald Lynch Boulevard, Marlborough MA 01752 - 9130.
  