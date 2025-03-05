// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &v, vector<int> &w, vector<vector<int>> &dp, int i, int maxW)
{
    if (i < 0 || maxW <= 0)
        return 0;

    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    if (w[i] <= maxW)
    {
        int take = knapsack(v, w, dp, i - 1, maxW - w[i]) + v[i];
        int notTake = knapsack(v, w, dp, i - 1, maxW);

        return dp[i][maxW] = max(take, notTake);
    }
    else
        return dp[i][maxW] = knapsack(v, w, dp, i - 1, maxW);
}

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> weight(N), value(N);
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));

    for (int i = 0; i < N; i++)
        cin >> weight[i] >> value[i];

    cout << knapsack(value, weight, dp, N - 1, W);
    return 0;
}