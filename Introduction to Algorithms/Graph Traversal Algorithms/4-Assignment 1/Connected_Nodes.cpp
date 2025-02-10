#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices);
    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int query;
    cin >> query;

    while (query--)
    {
        int x;
        cin >> x;

        if (adj_list[x].empty())
            cout << -1 << endl;
        else
        {
            sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());
            for (int val : adj_list[x])
                cout << val << " ";

            cout << endl;
        }
    }

    return 0;
}