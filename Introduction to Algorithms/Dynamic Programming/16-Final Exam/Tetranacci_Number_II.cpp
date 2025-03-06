#include <bits/stdc++.h>
using namespace std;

long long tetranacci(int n)
{
    if (n <= 0)
        return 0;
    else if (n <= 2)
        return 1;
    else if (n == 3)
        return 2;

    vector<long long> dp(n + 1);
    dp[0] = 0, dp[1] = 1, dp[2] = 1, dp[3] = 2;

    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1];

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << tetranacci(n);
    return 0;
}