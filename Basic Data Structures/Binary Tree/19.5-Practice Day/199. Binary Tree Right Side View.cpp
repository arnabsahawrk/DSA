// https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        bool freq[101] = {false};
        queue<pair<TreeNode *, int>> q;
        if (root)
            q.push({root, 1});

        while (!q.empty())
        {
            pair<TreeNode *, int> parent = q.front();
            q.pop();

            if (!freq[parent.second])
            {
                ans.push_back(parent.first->val);
                freq[parent.second] = true;
            }
            else if (freq[parent.second])
            {
                ans.pop_back();
                ans.push_back(parent.first->val);
            }

            if (parent.first->left)
                q.push({parent.first->left, parent.second + 1});
            if (parent.first->right)
                q.push({parent.first->right, parent.second + 1});
        }

        return ans;
    }
};