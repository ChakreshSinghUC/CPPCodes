//https://leetcode.com/problems/merge-two-binary-trees/description/
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *addNode(int x)
{
    TreeNode *N = new TreeNode(x);
    return N;
}
class Solution
{
  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {

        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
    void preOrderPrint(TreeNode *t)
    {
        cout << t->val << "\t";
        if (t->left)
            preOrderPrint(t->left);
        if (t->right)
            preOrderPrint(t->right);
    }
};
int main()
{
    TreeNode *t1, *t2;
    t1 = addNode(1);
    t1->left = addNode(3);
    t1->left->left = addNode(5);
    t1->right = addNode(2);

    t2 = addNode(1);
    t2->left = addNode(2);
    t2->left->right = addNode(4);
    t2->right = addNode(3);
    t2->right->right = addNode(7);

    Solution obj;
    TreeNode *t = obj.mergeTrees(t1, t2);
    if (t)
        obj.preOrderPrint(t);
}