#include <bits/stdc++.h>
using namespace std;

vector<int> newArray(vector<int> v1, vector<int> v2, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(v2[i]);

    for (int i = 0; i < n; i++)
        v.push_back(v1[i]);

    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        cin >> v2[i];

    vector<int> v3 = newArray(v, v2, n);

    for (auto numb : v3)
        cout << numb << " ";

    return 0;
}