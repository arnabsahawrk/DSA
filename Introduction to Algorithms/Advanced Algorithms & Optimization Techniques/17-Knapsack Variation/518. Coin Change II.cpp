// https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> dp;

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));

        return unbounded_knapsack(n - 1, amount, coins);
    }

private:
    int unbounded_knapsack(int i, int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        else if (i < 0)
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        if (coins[i] <= amount)
        {
            return dp[i][amount] = unbounded_knapsack(i, amount - coins[i], coins) + unbounded_knapsack(i - 1, amount, coins);
        }
        else
            return dp[i][amount] = unbounded_knapsack(i - 1, amount, coins);
    }
};