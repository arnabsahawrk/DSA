#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> adj_list, vector<bool> visited, int source_node)
{
    queue<int> q; // space complexity: O(V)

    q.push(source_node);
    visited[source_node] = true;

    while (!q.empty()) // O(V) where V is number of vertices
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for (int child : adj_list[parent]) // O(E) where E is number of edges
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
            }
        }
    } // time complexity: O(V + E)
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices);
    vector<bool> visited(vertices, false);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs_traversal(adj_list, visited, 0);

    return 0;
}