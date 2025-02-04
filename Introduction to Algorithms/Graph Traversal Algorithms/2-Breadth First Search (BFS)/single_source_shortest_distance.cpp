#include <bits/stdc++.h>
using namespace std;

int shortest_distance(vector<vector<int>> list, vector<bool> vis, vector<int> lev, int src, int des)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lev[src] = lev[src] + 1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int x : list[par])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
                lev[x] = lev[par] + 1;
            }
        }
    }

    return lev[des];
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjacency_list(vertices);
    vector<bool> visited(vertices, false);
    vector<int> level(vertices, -1);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    int source_node, destination;
    cin >> source_node >> destination;

    int distance = shortest_distance(adjacency_list, visited, level, source_node, destination);

    if (distance != -1)
        cout << distance << endl;
    else
        cout << "Can Not Be Visited" << endl;

    return 0;
}