// https://www.naukri.com/code360/problems/diameter-of-the-binary-tree_920552
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int maxDiameter = 0;

int diameter(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = diameter(root->left);
    int right = diameter(root->right);
    int d = left + right;
    maxDiameter = max(d, maxDiameter);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    diameter(root);
    return maxDiameter;
}
