#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj_list(vertices);

    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    int i = 0;
    for (auto arr : adj_list)
    {
        cout << i << " -> ";

        for (auto p : arr)
            cout << p.first << " " << p.second << ", ";

        cout << endl;
        i++;
    }

    return 0;
}