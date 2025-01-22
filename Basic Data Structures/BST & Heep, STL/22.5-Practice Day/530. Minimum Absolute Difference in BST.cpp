// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        inorderTraversal(root, ans);
        return ans;
    }

private:
    int prev = -1;
    void inorderTraversal(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return;

        inorderTraversal(root->left, ans);
        if (prev >= 0)
            ans = min(ans, root->val - prev);
        prev = root->val;
        inorderTraversal(root->right, ans);
    }
};