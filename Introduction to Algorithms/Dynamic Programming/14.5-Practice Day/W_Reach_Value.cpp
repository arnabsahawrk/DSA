// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
#include <bits/stdc++.h>
using namespace std;

bool reach_value(long long n, long long i)
{
    if (i > n)
        return false;
    else if (i == n)
        return true;

    return reach_value(n, i * 10) || reach_value(n, i * 20);
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        long long n;
        cin >> n;

        if (reach_value(n, 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}