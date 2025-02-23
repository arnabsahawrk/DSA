// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 100000000);
        dist[src] = 0;
        bool isUpdated = false;

        for (int i = 0; i < V; i++)
        {
            for (auto it : edges)
            {
                int u = it[0], v = it[1], w = it[2];

                if (dist[u] != 100000000 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    isUpdated = true;
                }
            }

            if (!isUpdated)
                break;
        }

        for (auto it : edges)
        {
            int u = it[0], v = it[1], w = it[2];

            if (dist[u] != 100000000 && dist[u] + w < dist[v])
                return {-1};
        }

        return dist;
    }
};
int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int N, m;
        cin >> N >> m;

        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}