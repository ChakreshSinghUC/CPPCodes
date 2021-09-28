#include <bits/stdc++.h>
using namespace std;
template <typename T>
class bst
{
  public:
    T a;
    bst(T x)
    {
        a = x;
    }
    unique_ptr<bst<T>> left, right;
};
template <typename T>
void traverseBST(unique_ptr<bst<T>> &root)
{

    if (root)
    {
        //  cout << "Preorder: " << root->a << "->";
        traverseBST(root->left);
        cout << root->a << "->";
        traverseBST(root->right);
        // cout << "Postorder: " << root->a << "->";
    }
}
int main()
{
    unique_ptr<bst<int>> r(new bst<int>(6));
    r->left = unique_ptr<bst<int>>(new bst<int>(3));
    r->right = unique_ptr<bst<int>>(new bst<int>(8));
    r->left->left = unique_ptr<bst<int>>(new bst<int>(2));
    r->left->right = unique_ptr<bst<int>>(new bst<int>(5));
    cout << "Inorder: ";
    traverseBST(r);
}