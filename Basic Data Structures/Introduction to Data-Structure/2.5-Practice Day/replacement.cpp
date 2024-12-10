// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) // O(n)
        cin >> v[i];

    for (int i = 0; i < n; i++) // O(n)
    {
        if (v[i] > 0)
            v[i] = 1;
        else if (v[i] < 0)
            v[i] = 2;
    }

    for (auto numb : v) // O(n)
        cout << numb << " ";
    return 0;
}
// O(n)