// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
            return 0;

        int l = height(root->left, diameter);
        int r = height(root->right, diameter);
        diameter = max(diameter, l + r);

        return max(l, r) + 1;
    }
};