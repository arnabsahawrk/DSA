#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int subset_sum(int i, vector<int> arr, int target) // O(n * target)
{
    if (target == 0)
        return 1;
    else if (i < 0)
        return 0;

    if (dp[i][target] != -1)
        return dp[i][target];

    if (arr[i] <= target)
        return dp[i][target] = subset_sum(i - 1, arr, target - arr[i]) || subset_sum(i - 1, arr, target);
    else
        return dp[i][target] = subset_sum(i - 1, arr, target);
}

int main()
{
    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int sum;
    cin >> sum;

    dp.resize(n, vector<int>(sum + 1, -1));

    if (subset_sum(n - 1, val, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}