#include <bits/stdc++.h>
using namespace std;

bool cycle_detection_using_dfs(vector<vector<int>> list, vector<bool> &vis, vector<int> &par, int src)
{
    vis[src] = true;

    for (int child : list[src])
    {
        if (vis[child] && par[src] != child)
            return true;

        if (!vis[child])
        {
            par[child] = src;
            if (cycle_detection_using_dfs(list, vis, par, child))
                return true;
        }
    }

    return false;
}

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

    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);

    for (int i = 0; i < vertices; i++)
    {
        bool cycle;
        if (!visited[i])
            cycle = cycle_detection_using_dfs(adj_list, visited, parent, i);

        if (cycle)
        {
            cout << "Cycle Detected" << endl;
            return 0;
        }
    }

    cout << "No Cycle" << endl;

    return 0;
}