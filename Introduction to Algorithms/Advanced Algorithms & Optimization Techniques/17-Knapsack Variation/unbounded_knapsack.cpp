#include <bits/stdc++.h>
using namespace std;
vector<int> value, weight;
vector<vector<int>> dp;

int unbounded_knapsack(int i, int maxW)
{
    if (i < 0 || maxW == 0)
        return 0;

    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    if (weight[i] <= maxW)
        return dp[i][maxW] = max(unbounded_knapsack(i, maxW - weight[i]) + value[i], unbounded_knapsack(i - 1, maxW));
    else
        return dp[i][maxW] = unbounded_knapsack(i - 1, maxW);
}

int main()
{
    int n;
    cin >> n;

    value.resize(n), weight.resize(n);
    for (int i = 0; i < n; i++)
        cin >> value[i] >> weight[i];

    int maxWeight;
    cin >> maxWeight;

    dp.resize(n, vector<int>(maxWeight + 1, -1));

    cout << unbounded_knapsack(n - 1, maxWeight) << endl;

    return 0;
}