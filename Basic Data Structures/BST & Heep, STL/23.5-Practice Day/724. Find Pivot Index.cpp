// https://leetcode.com/problems/find-pivot-index/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for (int i = 1; i < n; i++)
            leftSum[i] = leftSum[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; i--)
            rightSum[i] = rightSum[i + 1] + nums[i + 1];

        for (int i = 0; i < n; i++)
            if (leftSum[i] == rightSum[i])
                return i;

        return -1;
    }
};