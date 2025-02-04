#include <bits/stdc++.h>
using namespace std;

vector<int> path_printing(vector<vector<int>> adj_list, int src, int des)
{
    int vertices = adj_list.size();
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

        for (int child : adj_list[parent])
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

    int source_node, destination_node;
    cin >> source_node >> destination_node;

    vector<int> path = path_printing(adjacency_list, source_node, destination_node);

    if (path.empty())
        cout << "Can Not Be Visited";
    else
    {
        for (int p : path)
            cout << p << " ";
        cout << endl;
    }

    return 0;
}