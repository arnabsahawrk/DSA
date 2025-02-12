#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> list, int source_node)
{
    int vertices = list.size();
    vector<int> distance_array(vertices, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance_array[source_node] = 0;
    pq.push({distance_array[source_node], source_node});

    while (!pq.empty()) // O(V)
    {
        pair<int, int> parent = pq.top();
        pq.pop(); // O(logV)

        int parent_distance = parent.first;
        int parent_vertex = parent.second;

        for (auto child : list[parent_vertex]) // O(E)
        {
            int child_distance = child.second;
            int child_vertex = child.first;

            if (parent_distance + child_distance < distance_array[child_vertex])
            {
                distance_array[child_vertex] = parent_distance + child_distance;
                pq.push({distance_array[child_vertex], child_vertex}); // O(logV)
            }
        }
    }

    return distance_array;
} // time complexity: O(VlogV + ElogV) -> O((V + E)logV) for every vertices it goes its edges only one time and for priority queue O(logV) every time push/pop.

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