// https://leetcode.com/problems/univalued-binary-tree/
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
    bool isUnivalTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        if ((root->left && root->left->val != root->val) || (root->right && root->right->val != root->val))
            return false;

        bool left = isUnivalTree(root->left);
        bool right = isUnivalTree(root->right);

        return left && right;
    }
};