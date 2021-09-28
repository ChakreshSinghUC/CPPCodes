// https://leetcode.com/problems/balanced-binary-tree/

#include <iostream>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int height(TreeNode *root)
    {
        // An empty tree has height -1
        if (root == NULL)
        {
            return -1;
        }
        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // An empty tree satisfies the definition of a balanced tree
        if (root == NULL)
        {
            return true;
        }

        // Check if subtrees have height within 1. If they do, check if the
        // subtrees are balanced
        return abs(height(root->left) - height(root->right)) < 2 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout<<obj.isBalanced(root);
}
