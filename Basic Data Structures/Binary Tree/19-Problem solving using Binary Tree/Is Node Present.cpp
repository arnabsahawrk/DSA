// https://www.naukri.com/code360/problems/code-find-a-node_5682
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
        return false;

    if (root->data == x)
        return true;

    bool left = isNodePresent(root->left, x);
    bool right = isNodePresent(root->right, x);

    return left || right;
}