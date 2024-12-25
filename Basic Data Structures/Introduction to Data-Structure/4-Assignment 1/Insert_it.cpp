#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cin >> n;

    a.insert(a.begin() + n, b.begin(), b.end());

    for (auto numb : a)
        cout << numb << " ";
    return 0;
}