// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorder(vector<int> &v, TreeNode *root)
    {
        if (root == nullptr)
            return v;

        postorder(v, root->left);
        postorder(v, root->right);
        v.push_back(root->val);

        return v;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;

        return postorder(v, root);
    }
};