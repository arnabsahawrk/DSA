#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<vector<int>> adj_l, int src, int des)
{
    int vertices = adj_l.size();
    vector<bool> visited(vertices, false);
    vector<int> parent_list(vertices, -1);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent_list[src] = src;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj_l[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent_list[child] = parent;
            }
        }
    }

    vector<int> path;

    if (visited[des])
    {
        for (int node = des; node != src; node = parent_list[node])
            path.push_back(node);

        path.push_back(src);

        reverse(path.begin(), path.end());
    }

    return path;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjacency_list(vertices);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    int source_node, destination;
    cin >> source_node >> destination;

    vector<int> path = shortest_path(adjacency_list, source_node, destination);

    if (path.empty())
        cout << "Can Not Be Visited" << endl;
    else
    {
        for (int p : path)
            cout << p << " ";
    }

    return 0;
}