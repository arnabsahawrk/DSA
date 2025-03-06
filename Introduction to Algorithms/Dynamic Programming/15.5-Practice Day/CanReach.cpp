/*
Input Format:
First line will contain T, the number of test cases.
In each test case you will be given N.

You will be given a positive integer N. You will start from 1 and do some steps (possibly zero).

In each step you can choose one of the following:
1. Add 5 with the current value
2. Multiply by 4 with the current value
Can you tell if you can reach N by using any number of steps you want.

Constraints
1<=T<=10^3
1<=N<=10^5

Output Format:
Print "YES" if you can reach , "NO" otherwise.

Sample Input 0
6
1
3
6
15
16
64

Sample Output 0
YES
NO
YES
NO
YES
YES
*/
#include <bits/stdc++.h>
using namespace std;

bool canReach(int i, int target, vector<int> &dp)
{
    if (i > target)
        return false;
    if (i == target)
        return true;

    if (dp[i] != -1)
        return dp[i];

    return dp[i] = canReach(i + 5, target, dp) || canReach(i * 4, target, dp);
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> dp(n + 1, -1);

        if (canReach(1, n, dp))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}