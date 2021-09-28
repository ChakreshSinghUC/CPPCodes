#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

  public:
    int count = 0;
    void inOrderTraversal(TreeNode *node, int L, int R)
    {
        if (node == NULL)
            return;
        inOrderTraversal(node->left, L, R);
        if (node->val >= L && node->val <= R)
        {
             count += node->val;
        }
        inOrderTraversal(node->right, L, R);
    }
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int ans = 0;

        inOrderTraversal(root, L, R);

        return count;
    }
};

int main()
{
    TreeNode *root;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    Solution obj;
    int L = 6;
    int R = 10;
    cout << obj.rangeSumBST(root, L, R);
}