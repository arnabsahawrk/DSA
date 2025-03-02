#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n, vector<long long> &dp) // O(n)
{
    if (n <= 1) // base case
        return n;

    if (dp[n] != -1) // memorization process (check if already computed)
        return dp[n];

    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp); // store result in dp
} // space complexity: O(n)

int main()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1, -1); // initialize memorization table

    cout << fibonacci(n, dp);
    return 0;
}