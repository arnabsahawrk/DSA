// https://codeforces.com/problemset/problem/4/C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<string, int> mp;

    while (t--)
    {
        string username;
        cin >> username;
        mp[username]++;

        if (mp[username] == 1)
            cout << "OK" << endl;
        else
            cout << username << mp[username]-1 << endl;
    }
    return 0;
}