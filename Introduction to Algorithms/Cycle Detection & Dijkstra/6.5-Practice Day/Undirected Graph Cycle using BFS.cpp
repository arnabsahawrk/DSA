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
                cycle = bfs(adj, visited, parent, i);

            if (cycle)
                return true;
        }

        return false;
    }

private:
    bool bfs(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &par, int src)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            int p = q.front();
            q.pop();

            for (int child : adj[p])
            {
                if (vis[child] && par[p] != child)
                    return true;

                if (!vis[child])
                {
                    q.push(child);
                    par[child] = p;
                    vis[child] = true;
                }
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