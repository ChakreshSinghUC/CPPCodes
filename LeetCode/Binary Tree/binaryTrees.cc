#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
    int post_idx;
    vector<int> _inorder;
    vector<int> _postorder;
    map<int, int> m;

public:
    static inline TreeNode *DELIMITER = nullptr;
    vector<TreeNode *> inorder_bst;
    void recoverTree(TreeNode *recover_root)
    {
        // https://leetcode.com/problems/recover-binary-search-tree/
        inorder(recover_root);

        vector<TreeNode *> v = inorder_bst;
        vector<int> v_sorted;
        for (auto a : v)
        {
            v_sorted.push_back(a->val);
        }
        sort(v_sorted.begin(), v_sorted.end());
        int N = v_sorted.size();
        int l, r;
        for (int i = 0; i < N; i++)
        {

            if (v_sorted[i] != v[i]->val)
            {
                l = v_sorted[i];
                r = v[i]->val;
                break;
            }
        }

        TreeNode *left, *right;
        for (auto a : v)
        {
            if (a->val == l)
                left = a;
            if (a->val == r)
                right = a;
        }

        left->val = r;
        right->val = l;

        inorder(recover_root);
        cout << endl;
        for (auto a : v)
        {
            cout << a->val << "\t";
        }
    }

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
                
                if (curr->left != nullptr)
                    Q.push(curr->left);
                if (curr->right != nullptr)
                    Q.push(curr->right);
                cout << curr->val << "->";
                // lastNode = curr->val;
                }
            else
            {
                cout << endl;
                // right side view of the tree
                // cout << lastNode << endl;
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
        // cout << root->val << "->";
        inorder_bst.push_back(root);
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

    TreeNode *helper(int in_left, int in_right)
    {
        if (in_left > in_right)
            return nullptr;
        int root_val = _postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);

        int index = m[root_val];
        post_idx--;
        root->right = helper(index + 1, in_right);
        root->left = helper(in_left, index - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &_inorder, vector<int> &_postorder)
    {
        this->_postorder = _postorder;
        this->_inorder = _inorder;

        post_idx = _postorder.size() - 1;
        int idx = 0;

        for (auto a : _inorder)
            m.insert(pair<int, int>(a, idx++));

        return helper(0, _inorder.size() - 1);
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
    vector<int> p{9, 15, 7, 20, 3};
    vector<int> i{9, 3, 15, 20, 7};
    Solution o;


    // o.buildTree(i, p);
    // o.inorder(root);
    // cout << endl;
    o.levelOrder(root);
    // o.validateBST(root);

/*
                        3
                       / \
                      1   4
                         /
                        2 
*/
    TreeNode *recover_root = new TreeNode(3);
    recover_root->left = new TreeNode(1);
    recover_root->right = new TreeNode(4);
    recover_root->right->left = new TreeNode(2);
    // o.recoverTree(recover_root);
}
