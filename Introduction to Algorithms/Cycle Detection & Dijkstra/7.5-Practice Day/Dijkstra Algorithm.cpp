// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int len = adj.size();
        vector<int> des(len, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        des[src] = 0;
        pq.push({des[src], src});

        while (!pq.empty())
        {
            pair<int, int> parent = pq.top();
            pq.pop();

            int parent_des = parent.first;
            int parent_node = parent.second;

            for (auto child : adj[parent_node])
            {
                int child_node = child.first;
                int child_des = child.second;

                if (parent_des + child_des < des[child_node])
                {
                    des[child_node] = parent_des + child_des;
                    pq.push({des[child_node], child_node});
                }
            }
        }

        return des;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}