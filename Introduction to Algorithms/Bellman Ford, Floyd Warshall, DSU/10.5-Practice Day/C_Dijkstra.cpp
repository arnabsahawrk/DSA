// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj_list)
{
    int v = adj_list.size();

    vector<long long> dist(v, LLONG_MAX);
    vector<int> parent(v, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[0] = 0;
    parent[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int p = pq.top().second;
        pq.pop();

        for (auto c : adj_list[p])
        {
            int cc = c.first;
            int cd = c.second;

            long long nextDist = cd + d;

            if (nextDist < dist[cc])
            {
                dist[cc] = nextDist;
                parent[cc] = p;
                pq.push({nextDist, cc});
            }
        }
    }

    return parent;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj_list(vertices);

    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    vector<int> parent = dijkstra(adj_list);

    if (parent[vertices - 1] == -1 && vertices > 1)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    int p = vertices - 1;
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