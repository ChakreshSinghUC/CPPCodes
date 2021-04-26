// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

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
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = new TreeNode();

        if (!nums.empty())
        {
            int mid = nums.size() / 2;
            root->val = nums[mid];
            vector<int> left_num(nums.begin(), nums.begin() + mid);
            vector<int> right_num(nums.begin() + mid, nums.end());

            root->left = sortedArrayToBST(left_num);
            root->right = sortedArrayToBST(right_num);
        }
        return root;
    }
};

int main()
{
    vector<int> nums{-10, -3, 0, 5, 9};
    vector<int> n(nums.begin(), nums.begin() + 3);
//    TreeNode *root = new TreeNode(0);
//    root->left = new TreeNode(-3);
//    root->left->left = new TreeNode(-10);
//    root->right = new TreeNode(9);
//    root->right->left = new TreeNode(5);


}