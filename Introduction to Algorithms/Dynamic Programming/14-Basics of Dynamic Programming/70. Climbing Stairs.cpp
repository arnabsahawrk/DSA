// https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibonacci(n, dp);
    }

private:
    int fibonacci(int n, vector<int> &dp)
    {
        if (n < 3)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    }
};