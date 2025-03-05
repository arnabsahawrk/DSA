#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> cost, vector<int> weight, int i, int maxW)
{
    if (i < 0 || maxW <= 0)
        return 0;

    if (weight[i] <= maxW)
    {
        int take = knapsack(cost, weight, i - 1, maxW - weight[i]) + cost[i];
        int notTake = knapsack(cost, weight, i - 1, maxW);

        return max(take, notTake);
    }
    else
    {
        return knapsack(cost, weight, i - 1, maxW);
    }
} // time complexity: O(2^n)

int main()
{
    int n, max_weight;
    cin >> n;

    vector<int> cost(n), weight(n);

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int j = 0; j < n; j++)
        cin >> weight[j];

    cin >> max_weight;

    cout << knapsack(cost, weight, n - 1, max_weight);
    return 0;
}