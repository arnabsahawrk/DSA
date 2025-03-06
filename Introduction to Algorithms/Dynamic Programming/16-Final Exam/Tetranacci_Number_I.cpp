#include <bits/stdc++.h>
using namespace std;

int tetranacci(int n, vector<long long> &dp)
{
    if (n <= 0)
        return 0;
    else if (n <= 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tetranacci(n - 4, dp) + tetranacci(n - 3, dp) + tetranacci(n - 2, dp) + tetranacci(n - 1, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<long long> dp(n + 1, -1);

    cout << tetranacci(n, dp);
    return 0;
}