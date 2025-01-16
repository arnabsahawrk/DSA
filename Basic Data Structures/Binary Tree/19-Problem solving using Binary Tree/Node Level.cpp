// https://www.naukri.com/code360/problems/node-level_920383
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    bool isOriginal;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int nodeLevel(TreeNode<int> *root, int searchedValue)
{
    queue<pair<TreeNode<int> *, int>> q;

    if (root)
        q.push(make_pair(root, 1));

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> parent = q.front();
        q.pop();

        if (parent.first->val == searchedValue)
            return parent.second;

        if (parent.first->left)
            q.push({parent.first->left, parent.second + 1});
        if (parent.first->right)
            q.push({parent.first->right, parent.second + 1});
    }

    return 0;
}
