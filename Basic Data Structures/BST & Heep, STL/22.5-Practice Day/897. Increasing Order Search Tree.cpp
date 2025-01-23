// https://leetcode.com/problems/increasing-order-search-tree/
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
    TreeNode *increasingBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        inorderTraversal(root, st);

        TreeNode *newRoot = nullptr;
        while (!st.empty())
        {
            TreeNode *r = st.top();
            st.pop();
            r->left = nullptr;
            r->right = newRoot;
            newRoot = r;
        }

        return newRoot;
    }

private:
    void inorderTraversal(TreeNode *root, stack<TreeNode *> &st)
    {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, st);
        st.push(root);
        inorderTraversal(root->right, st);
    }
};