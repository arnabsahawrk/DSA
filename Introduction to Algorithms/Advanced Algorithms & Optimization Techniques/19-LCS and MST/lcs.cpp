#include <bits/stdc++.h>
using namespace std;
string str1, str2;
vector<vector<int>> dp;

int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    else
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
}

int main()
{
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    dp.resize(n, vector<int>(m, -1));

    int lengthOfCommonSubsequence = lcs(n - 1, m - 1);

    cout << lengthOfCommonSubsequence << endl;

    return 0;
}