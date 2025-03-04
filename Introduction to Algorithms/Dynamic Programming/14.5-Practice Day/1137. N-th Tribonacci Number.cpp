// https://leetcode.com/problems/n-th-tribonacci-number/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> v(n + 1, -1);
        return f(n, v);
    }

private:
    int f(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = f(n - 1, dp) + f(n - 2, dp) + f(n - 3, dp);
    }
};