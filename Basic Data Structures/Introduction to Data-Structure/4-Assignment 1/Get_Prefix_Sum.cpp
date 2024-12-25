#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        v[i] = sum;
    }

    reverse(v.begin(), v.end());

    for (auto numb : v)
        cout << numb << " ";

    return 0;
}