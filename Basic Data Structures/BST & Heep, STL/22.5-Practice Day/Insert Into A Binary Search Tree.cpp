// https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
};

TreeNode<int> *insertionInBST(TreeNode<int> *root, int val)
{
    if (root == nullptr)
        return new TreeNode<int>(val);

    if (val > root->val)
        root->right = insertionInBST(root->right, val);
    else
        root->left = insertionInBST(root->left, val);

    return root;
}