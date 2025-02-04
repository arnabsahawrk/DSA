#include <bits/stdc++.h>
using namespace std;

int shortestDistance(vector<vector<int>> adj_list, int src, int des)
{
    int len = adj_list.size();
    vector<bool> visited(len, false);
    vector<int> level(len, -1);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = level[src] + 1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj_list[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;
            }
        }
    }

    return level[des];
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices+1);

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
        int source_node, destination;
        cin >> source_node >> destination;

        cout << shortestDistance(adj_list, source_node, destination) << endl;
    }

    return 0;
}