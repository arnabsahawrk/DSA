// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Y

// Concept: Prefix Sum, Time Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) // O(N)
    {
        cin >> v[i];
        sum += v[i];
        v[i] = sum;
    }

    while (q--) // O(Q)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l != 0)
            cout << v[r] - v[l - 1] << endl;
        else
            cout << v[r] << endl;
    }

    return 0;
}

// O(N)