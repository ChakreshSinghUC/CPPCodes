
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
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *ans; 
    }

    void inoroder(TreeNode *root)
    {
        if (root == nullptr)
            return; 
        inoroder(root->left);
        cout << root->val<<"->";
        inoroder(root->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    
    Solution obj;
    obj.inoroder(root);


}