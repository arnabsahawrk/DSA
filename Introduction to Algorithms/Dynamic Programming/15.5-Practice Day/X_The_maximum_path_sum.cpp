// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X
#include <bits/stdc++.h>
using namespace std;

int maxPath(int i, int j, int r, int c, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i >= r || j >= c)
        return INT_MIN;
    if (i == r - 1 && j == c - 1)
        return arr[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = maxPath(i, j + 1, r, c, arr, dp);
    int down = maxPath(i + 1, j, r, c, arr, dp);

    return dp[i][j] = arr[i][j] + max(right, down);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout << maxPath(0, 0, n, m, arr, dp);
    return 0;
}
