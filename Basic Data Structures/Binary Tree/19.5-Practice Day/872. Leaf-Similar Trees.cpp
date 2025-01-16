// https://leetcode.com/problems/leaf-similar-trees/
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        v1 = leafNodes(root1, v1);
        v2 = leafNodes(root2, v2);

        if (v1 == v2)
            return true;
        else
            return false;
    }

private:
    vector<int> leafNodes(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
            return v;

        if (root->left == nullptr && root->right == nullptr)
            v.push_back(root->val);

        leafNodes(root->left, v);
        leafNodes(root->right, v);

        return v;
    }
};