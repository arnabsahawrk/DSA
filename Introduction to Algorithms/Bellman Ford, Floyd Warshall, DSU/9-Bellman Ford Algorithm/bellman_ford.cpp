#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<int> bellman_ford(vector<Edge> edge_list, int source)
{
    int v = edge_list.size();
    vector<int> dis(v, INT_MAX);
    dis[source] = 0;

    while (--v) // O(V)
    {
        for (auto ed : edge_list) // O(E)
        {
            int a = ed.a, b = ed.b, c = ed.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    return dis;
} // Time Complexity: O(V * E)

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<Edge> edge_list;

    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    vector<int> dis = bellman_ford(edge_list, 0);

    for (int i = 0; i < dis.size(); i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}