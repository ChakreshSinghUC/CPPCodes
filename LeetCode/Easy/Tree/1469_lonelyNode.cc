// https://leetcode.com/problems/find-all-the-lonely-nodes/
//   Definition for a binary tree node.

#include <iostream>
#include <vector>

using namespace std;

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
public:
vector<int> r;
   void printSingles(TreeNode *root)
    {
        
        // Base case
        if (root == NULL)
            return;

        // If this is an internal node, recur for left
        // and right subtrees
        if (root->left != NULL && root->right != NULL)
        {
            printSingles(root->left);
            printSingles(root->right);
        }

        // If left child is NULL and right is not,
        // print right child
        // and recur for right child
        else if (root->right != NULL)
        {
            r.push_back(root->right->val);
            printSingles(root->right);
        }

        // If right child is NULL and left is
        // not, print left child
        // and recur for left child
        else if (root->left != NULL)
        {
            r.push_back(root->left->val);
            printSingles(root->left);
        }

    }
    vector<int> getLonelyNodes(TreeNode *root)
    {
        printSingles(root);
        return r;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);

    Solution obj;
    vector<int> r = obj.getLonelyNodes(root);
    for (auto t : r)
        cout << t << endl;
}