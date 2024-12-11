#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    if (n < 3)
    {
        cout << "NO EQULIBRIUM INDEX" << endl;
        return 0;
    }

    vector<ll> v(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) // O(N)
    {
        cin >> v[i];
        sum += v[i];
        v[i] = sum;
    }

    for (int i = 1; i < n - 1; i++) // O(N)
    {
        if (v[i - 1] == (v.back() - v[i]))
        {
            cout << i;
            return 0;
        }
    }

    cout << "NO EQULIBRIUM INDEX" << endl;

    return 0;
}

// Time Complexity: O(N)