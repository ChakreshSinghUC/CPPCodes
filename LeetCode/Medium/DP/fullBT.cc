// https://leetcode.com/problems/all-possible-full-binary-trees/

// Given an integer n, return a list of all possible full binary trees with n nodes. 
// Each node of each tree in the answer must have Node.val == 0.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.
// 1 <= n <= 20

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right){}
};

class Solution {
public:
  vector<TreeNode *> allPossibleFBT(int n){}
};

int main() {
  int n = 5;
  Solution o;
  o.allPossibleFBT(n);
}