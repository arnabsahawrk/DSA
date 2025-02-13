// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int src)
{
    vis[src] = true;

    for (int x : adj[src])
    {
        if (!vis[x])
            dfs(adj, vis, x);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(v, false);
    vector<int> newRoad;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, i);
            newRoad.push_back(i + 1);
        }
    }

    cout << newRoad.size() - 1 << endl;

    for (int i = 0; i < newRoad.size() - 1; i++)
        cout << newRoad[i] << " " << newRoad[i + 1] << endl;

    return 0;
}