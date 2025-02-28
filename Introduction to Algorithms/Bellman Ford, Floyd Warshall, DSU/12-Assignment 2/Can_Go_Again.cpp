#include <bits/stdc++.h>
using namespace std;

vector<long long> bellman_ford(int n, vector<pair<int, pair<int, int>>> &edges, int source)
{
    vector<long long> dist(n, LLONG_MAX);
    dist[source] = 0;

    while (n--)
    {
        for (auto it : edges)
        {
            int u = it.first, v = it.second.first, w = it.second.second;

            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    return dist;
}

int main()
{
    int N, E, source, query;
    cin >> N >> E;

    vector<pair<int, pair<int, int>>> edge_list;

    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edge_list.push_back({u, {v, w}});
    }

    cin >> source;
    source--;

    vector<long long> dist = bellman_ford(N, edge_list, source);

    for (auto it : edge_list)
    {
        int u = it.first, v = it.second.first, w = it.second.second;

        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    cin >> query;

    while (query--)
    {
        int destination;
        cin >> destination;
        destination--;

        if (dist[destination] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dist[destination] << endl;
    }

    return 0;
}