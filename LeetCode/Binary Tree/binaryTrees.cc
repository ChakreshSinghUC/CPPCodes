#include <iostream>
#include <vector>
#include <queue>

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
    static inline TreeNode *DELIMITER = nullptr;
    void levelOrder(TreeNode *root)
    {
        //print Tree level by level
        if (root == nullptr)
            return;

        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(DELIMITER);
        int lastNode;
        while (!Q.empty())
        {
            TreeNode *curr = Q.front();
            Q.pop();
            if (curr != DELIMITER)
            {
                // cout << curr->val << "->";
                if (curr->left != nullptr)
                    Q.push(curr->left);
                if (curr->right != nullptr)
                    Q.push(curr->right);

                lastNode = curr->val;
            }
            else
            {
                // right side view of the tree
                cout << lastNode << endl;
                if (Q.empty())
                    break;
                Q.push(DELIMITER);
            }
        }
    }
    void preorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        cout << root->val << "->";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->val << "->";
        inorder(root->right);
    }
    TreeNode *prev;
    bool validateBST_util(TreeNode *root)
    {
        if (root == nullptr)
            return 1;

        if (!validateBST_util(root->left))
            return 0;
        if (prev != nullptr && root->val <= prev->val)
            return false;
        prev = root;
        return validateBST_util(root->right);
    }

    void validateBST(TreeNode *root)
    {
    (validateBST_util(root)) ? cout << "\nIs it a valid BST:True" : cout << "\nIs it a valid BST:False";
    }
};

int main()
{
    /*
                     5
                   /   \
                  2     7
                /  \   / \  
               1    3 6    8
    */
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution o;
    o.inorder(root);
    cout << endl;
    o.levelOrder(root); 
    o.validateBST(root);
}
