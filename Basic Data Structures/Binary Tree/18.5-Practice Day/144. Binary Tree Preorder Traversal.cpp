// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return v;

        v.push_back(root->val);
        preorder(v, root->left);
        preorder(v, root->right);

        return v;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;

        return preorder(v, root);
    }
};