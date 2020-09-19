
#include <iostream>
#include <vector>
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
    vector<int> vec;
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            vec.clear();
            levelOrder_n(root, i);
            ret.push_back(vec);
        }
        return ret;
    }
    void levelOrder_n(TreeNode *root, int l)
    {
        if (root == NULL)
            return;
        if (l == 1)
        {
            vec.push_back(root->val);
            return;
        }
        else if (l > 1)
        {
            levelOrder_n(root->left, l - 1);
            levelOrder_n(root->right, l - 1);
        }
    }
    int height( TreeNode *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
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
    vector<vector<int>> ret = obj.levelOrder(root);
    for (int i = 0; i < ret.size(); i++)
    {
        for (auto a : ret[i])
        {
            cout << a << " ";
        }
        cout << endl;
    }
}