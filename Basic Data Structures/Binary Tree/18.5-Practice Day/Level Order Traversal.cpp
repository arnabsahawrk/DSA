// https://www.naukri.com/code360/problems/level-order-traversal_796002
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        ans.push_back(front->val);

        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }

    return ans;
}