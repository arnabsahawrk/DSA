#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<vector<int>> dp;

bool subset_sum(int i, int half)
{
    if (half == 0)
        return true;
    else if (i < 0)
        return false;

    if (dp[i][half] != -1)
        return dp[i][half];

    if (arr[i] <= half)
    {
        return subset_sum(i - 1, half - arr[i]) || subset_sum(i - 1, half);
    }
    else
        return subset_sum(i - 1, half);
}

int main()
{
    int n;
    cin >> n;

    arr.resize(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }

    if (totalSum % 2 == 0)
    {
        dp.resize(n, vector<int>(totalSum + 1, -1));

        if (subset_sum(n - 1, totalSum / 2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}