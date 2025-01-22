// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return convertArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *convertArrayToBST(vector<int> array, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(array[mid]);

        root->left = convertArrayToBST(array, start, mid - 1);
        root->right = convertArrayToBST(array, mid + 1, end);

        return root;
    }
};