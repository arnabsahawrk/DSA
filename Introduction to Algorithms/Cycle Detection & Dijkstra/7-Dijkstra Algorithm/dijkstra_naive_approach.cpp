#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> list, int sourc_node)
{
    int vertices = list.size();
    vector<int> distance_array(vertices, INT_MAX);

    queue<pair<int, int>> q;
    distance_array[sourc_node] = 0;
    q.push({sourc_node, distance_array[sourc_node]});

    while (!q.empty()) // O(V)
    {
        pair<int, int> parent = q.front();
        q.pop();

        int parent_node = parent.first;
        int parent_distance = parent.second;

        for (auto child : list[parent_node]) // O(E)
        {
            int child_node = child.first;
            int child_distance = child.second;

            if (parent_distance + child_distance < distance_array[child_node])
            {
                distance_array[child_node] = parent_distance + child_distance;
                q.push({child_node, distance_array[child_node]});
            }
        }
    }

    return distance_array;
} // time_complexity: O(V * E) for every vertices it goes its edges every time

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> adj_list(vertices);

    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    vector<int> distance_array = dijkstra(adj_list, 0);

    int i = 0;
    for (auto distance : distance_array)
    {
        cout << i << " -> " << distance << endl;
        i++;
    }

    return 0;
}