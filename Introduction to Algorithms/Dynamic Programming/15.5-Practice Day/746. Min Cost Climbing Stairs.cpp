// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);

        return min(knapsack(cost, dp, n - 1), knapsack(cost, dp, n - 2));
    }

private:
    int knapsack(vector<int> &c, vector<int> &dp, int i)
    {
        if (i < 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int takeOne = knapsack(c, dp, i - 1) + c[i];
        int takeTwo = knapsack(c, dp, i - 2) + c[i];

        return dp[i] = min(takeOne, takeTwo);
    }
};