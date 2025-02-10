#include <bits/stdc++.h>
using namespace std;

bool cycle_detection_using_bfs(vector<vector<int>> list, vector<bool> &vis, int sourc_node)
{
    int len = list.size();
    vector<int> parent(len, -1);

    queue<int> q;
    q.push(sourc_node);
    vis[sourc_node] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : list[par])
        {
            if (vis[child] && parent[par] != child)
                return true;

            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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

    for (int i = 0; i < vertices; i++)
    {
        bool cycle;
        if (!visited[i])
            cycle = cycle_detection_using_bfs(adj_list, visited, i);

        if (cycle)
        {
            cout << "Cycle Detected" << endl;
            return 0;
        }
    }

    cout << "No Cycle" << endl;

    return 0;
}