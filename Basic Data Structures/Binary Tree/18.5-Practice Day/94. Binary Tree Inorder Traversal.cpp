// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;

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
    vector<int> inorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return v;

        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);

        return v;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;

        return inorder(v, root);
    }
};