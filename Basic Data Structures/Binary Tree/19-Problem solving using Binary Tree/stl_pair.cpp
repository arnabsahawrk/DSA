#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p;
    p = make_pair(2, 3);

    cout << p.first << " " << p.second << endl;

    pair<string, int> p2;
    p2 = {"Hello", 5};
    cout << p2.first << " " << p2.second << endl;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    for (int j = 0; j < n; j++)
        cout << v[j].first << " " << v[j].second << endl;

    return 0;
}