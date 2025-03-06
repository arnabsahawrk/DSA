#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &val, vector<int> &w, vector<vector<int>> &dp, int i, int maxW)
{
    if (i < 0 || maxW <= 0)
        return 0;

    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    if (w[i] <= maxW)
        return dp[i][maxW] = max(knapsack(val, w, dp, i - 1, maxW - w[i]) + val[i], knapsack(val, w, dp, i - 1, maxW));
    else
        return dp[i][maxW] = knapsack(val, w, dp, i - 1, maxW);
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, w;
        cin >> n >> w;

        vector<int> weight(n), value(n);
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));

        for (int i = 0; i < n; i++)
            cin >> weight[i];

        for (int j = 0; j < n; j++)
            cin >> value[j];

        cout << knapsack(value, weight, dp, n - 1, w) << endl;
    }

    return 0;
}