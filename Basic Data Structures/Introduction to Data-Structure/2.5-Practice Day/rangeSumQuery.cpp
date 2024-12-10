#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) // O(n)
    {
        cin >> v[i];
        sum += v[i];
        v[i] = sum;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (l > 1)
            cout << v[r - 1] - v[l - 2] << endl;
        else
            cout << v[r - 1] << endl;
    }

    return 0;
}
// O(n)