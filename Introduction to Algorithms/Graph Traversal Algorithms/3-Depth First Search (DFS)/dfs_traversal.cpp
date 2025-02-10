#include <bits/stdc++.h>
using namespace std;

void dfs_traversal(vector<vector<int>> adj_list, vector<bool> &visited, int source)
{
    cout << source << " ";
    visited[source] = true;

    for (int child : adj_list[source])
        if (!visited[child])
            dfs_traversal(adj_list, visited, child);
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
    dfs_traversal(adj_list, visited, 0);

    return 0;
}