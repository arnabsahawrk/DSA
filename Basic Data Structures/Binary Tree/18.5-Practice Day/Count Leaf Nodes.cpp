// https://www.naukri.com/code360/problems/count-leaf-nodes_893055
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

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    int left = noOfLeafNodes(root->left);
    int right = noOfLeafNodes(root->right);

    return left + right;
}