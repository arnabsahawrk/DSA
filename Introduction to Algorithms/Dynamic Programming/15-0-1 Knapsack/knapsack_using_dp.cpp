#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &c, vector<int> &w, vector<vector<int>> &dp, int i, int maxW)
{
    if (i < 0 || maxW <= 0)
        return 0;

    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    if (w[i] <= maxW)
    {
        int take = knapsack(c, w, dp, i - 1, maxW - w[i]) + c[i];
        int notTake = knapsack(c, w, dp, i - 1, maxW);

        return dp[i][maxW] = max(take, notTake);
    }
    else
        return dp[i][maxW] = knapsack(c, w, dp, i - 1, maxW);
} // time complexity: O(n * maxW)

int main()
{
    int n, maxWeight;
    cin >> n;

    vector<int> cost(n), weight(n);

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int j = 0; j < n; j++)
        cin >> weight[j];

    cin >> maxWeight;

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    cout << knapsack(cost, weight, dp, n - 1, maxWeight);
    return 0;
}