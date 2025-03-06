#include <bits/stdc++.h>
using namespace std;

void makeIt(vector<bool> &dp)
{
    dp[1] = true;
    for (int i = 1; i <= 10e5; i++)
    {
        if (dp[i])
        {
            if (i + 3 <= 10e5)
                dp[i + 3] = true;
            if (i * 2 <= 10e5)
                dp[i * 2] = true;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    vector<bool> dp(10e5, false);

    makeIt(dp);

    while (tc--)
    {
        int n;
        cin >> n;

        if (dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}