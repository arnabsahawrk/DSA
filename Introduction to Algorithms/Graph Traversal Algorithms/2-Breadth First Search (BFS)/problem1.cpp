#include <bits/stdc++.h>
using namespace std;

int shortest_distance(vector<vector<int>> adj_l, int src, int des)
{
    int vertices = adj_l.size();
    vector<bool> visited(vertices, false);
    vector<int> level(vertices, -1);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = level[src] + 1;

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

    int distance = shortest_distance(adjacency_list, source_node, destination);

    if (distance != -1)
        cout << distance << endl;
    else
        cout << "Can Not Be Visited" << endl;

    return 0;
}