#include <bits/stdc++.h>
using namespace std;

bool cycle_detection_using_dfs(vector<vector<int>> list, vector<bool> &vis, vector<bool> &pathVis, int src)
{
    vis[src] = true;
    pathVis[src] = true;

    for (int child : list[src])
    {
        if (vis[child] && pathVis[child])
            return true;

        if (!vis[child])
            if (cycle_detection_using_dfs(list, vis, pathVis, child))
                return true;
    }

    pathVis[src] = false;

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
    }

    vector<bool> visited(vertices, false);
    vector<bool> pathVisited(vertices, false);

    for (int i = 0; i < vertices; i++)
    {
        bool cycle;
        if (!visited[i])
            cycle = cycle_detection_using_dfs(adj_list, visited, pathVisited, i);

        if (cycle)
        {
            cout << "Cycle Detected" << endl;
            return 0;
        }
    }

    cout << "No Cycle" << endl;

    return 0;
}