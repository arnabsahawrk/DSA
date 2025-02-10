// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCycle(vector<vector<int>> &adj)
    {
        int vertices = adj.size();
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);

        bool cycle = false;

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
                cycle = dfs(adj, visited, parent, i);

            if (cycle)
                return cycle;
        }

        return cycle;
    }

private:
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &par, int src)
    {
        vis[src] = true;

        for (int child : adj[src])
        {
            if (vis[child] && par[src] != child)
                return true;

            if (!vis[child])
            {
                par[child] = src;
                if (dfs(adj, vis, par, child))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}