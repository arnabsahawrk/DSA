// https://www.naukri.com/code360/problems/left-view-of-a-binary-tree_920519
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

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    bool freq[3001] = {false};
    queue<pair<TreeNode<int> *, int>> q;

    if (root)
        q.push({root, 1});

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> parent = q.front();
        q.pop();

        if (!freq[parent.second])
        {
            ans.push_back(parent.first->data);
            freq[parent.second] = true;
        }

        if (parent.first->left)
            q.push({parent.first->left, parent.second + 1});
        if (parent.first->right)
            q.push({parent.first->right, parent.second + 1});
    }

    return ans;
}