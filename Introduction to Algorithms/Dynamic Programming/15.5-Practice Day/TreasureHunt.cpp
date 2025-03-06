/*
Treasure Hunt in a Mysterious Cave:
You are an adventurer who has discovered a hidden cave full of treasures. However, you can only carry a limited amount of weight in your backpack. Each treasure has a specific weight and a value. You must decide which treasures to take to maximize the total value while not exceeding your backpack’s weight limit.

Problem Statement
You have a backpack that can hold at most W kg.
There are N treasures in the cave, each with:
Value: 𝑣𝑖(gold coins)
Weight: 𝑤𝑖(kg)

You can either take a treasure (1) or leave it behind (0), meaning you cannot take a fraction of an item.


Input Example
Maximum Capacity: 𝑊=10 kg

Treasures List:
Gold Necklace: Weight = 3 kg, Value = 60
Silver Coins: Weight = 2 kg, Value = 40
Diamond Crown: Weight = 4 kg, Value = 90
Ruby Ring: Weight = 5 kg, Value = 100

Objective
Find the combination of treasures that maximizes the total value while ensuring the total weight does not exceed 10 kg.


Input format:
First line will contain T, the number of test cases.
The first line of each test case will contain N(Number of items) and W(Total weight of backpack).
Second line of each test case will contain an array w containing the weights of all items.
Third line of each test case will contain an array v containting the values of all items.


Sample Input 0
3
4 10
3 2 4 5
60 40 90 100
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8


Sample Output 0
200
13
28
*/
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &w, vector<int> &c, vector<vector<int>> &dp, int i, int maxW)
{
    if (i < 0 || maxW <= 0)
        return 0;

    if (dp[i][maxW] != -1)
        return dp[i][maxW];

    if (w[i] <= maxW)
        return dp[i][maxW] = max(knapsack(w, c, dp, i - 1, maxW - w[i]) + c[i], knapsack(w, c, dp, i - 1, maxW));
    else
        return dp[i][maxW] = knapsack(w, c, dp, i - 1, maxW);
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

        for (int i = 0; i < n; i++)
            cin >> weight[i];

        for (int i = 0; i < n; i++)
            cin >> value[i];

        vector<vector<int>> dp(n, vector<int>(w + 1, -1));

        cout << knapsack(weight, value, dp, n - 1, w) << endl;
    }

    return 0;
}