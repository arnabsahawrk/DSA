#include <bits/stdc++.h>
using namespace std;

bool visited_or_not(vector<vector<int>> adj_list, vector<bool> visited, int src, int des)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int x : adj_list[parent])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }

    return visited[des];
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjacency_list(vertices);
    vector<bool> visited(vertices, false);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    int source_node, destination;
    cin >> source_node >> destination;

    if (visited_or_not(adjacency_list, visited, source_node, destination))
        cout << "Can Be Visited" << endl;
    else
        cout << "Can Not Be Visited" << endl;

    return 0;
}