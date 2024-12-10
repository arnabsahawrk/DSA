// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) // O(n)
        cin >> v[i];

    reverse(v.begin(), v.end()); // O(n)

    for (auto numb : v) // O(n)
        cout << numb << " ";

    return 0;
}

// O(n)