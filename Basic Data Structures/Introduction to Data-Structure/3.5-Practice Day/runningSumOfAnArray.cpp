#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) // O(N)
    {
        cin >> v[i];
        sum += v[i];
        v[i] = sum;
    }

    for (auto numb : v) // O(N)
    {
        cout << numb << " ";
    }
    return 0;
}

// Time Complexity: O(N)