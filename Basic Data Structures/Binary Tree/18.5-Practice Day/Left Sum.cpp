// https://www.naukri.com/code360/problems/left-sum_920380
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

long long leftSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    long long sum = 0;

    if (root->left)
        sum += root->left->data;

    long long left = leftSum(root->left);
    long long right = leftSum(root->right);

    return left + right + sum;
}