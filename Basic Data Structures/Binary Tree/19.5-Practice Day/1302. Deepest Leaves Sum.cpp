// https://leetcode.com/problems/deepest-leaves-sum/
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
    int deepestLeavesSum(TreeNode *root)
    {
        int depth = height(root);

        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int sum = 0;
        while (!q.empty())
        {
            pair<TreeNode *, int> parent = q.front();
            q.pop();

            if (parent.second == depth)
                sum += parent.first->val;

            if (parent.first->left)
                q.push({parent.first->left, parent.second + 1});
            if (parent.first->right)
                q.push({parent.first->right, parent.second + 1});
        }

        return sum;
    }

private:
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }
};