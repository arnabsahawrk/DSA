// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> adj_list)
{
    int n = adj_list.size();
    vector<long long> dist(n, LLONG_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, 0});
    dist[0] = 0;
    parent[0] = 0;

    while (!pq.empty())
    {
        auto [d, p] = pq.top();
        pq.pop();

        for (auto c : adj_list[p])
        {
            auto [n, w] = c;

            if (d + w < dist[n])
            {
                dist[n] = d + w;
                pq.push({dist[n], n});
                parent[n] = p;
            }
        }
    }

    return parent;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj_list(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    vector<int> parent = dijkstra(adj_list);

    if (parent[n - 1] == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    int p = n - 1;
    while (true)
    {
        path.push_back(p + 1);
        if (p == 0)
            break;

        p = parent[p];
    }

    reverse(path.begin(), path.end());

    for (int val : path)
        cout << val << " ";

    return 0;
}