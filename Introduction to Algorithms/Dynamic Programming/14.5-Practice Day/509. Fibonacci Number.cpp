// https://leetcode.com/problems/fibonacci-number/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        vector<int> v(n + 1, -1);
        return f(n, v);
    }

private:
    int f(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }
};