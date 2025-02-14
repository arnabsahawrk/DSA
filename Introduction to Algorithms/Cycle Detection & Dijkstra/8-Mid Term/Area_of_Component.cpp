#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<char>> &adj, vector<vector<bool>> &vis, int i, int j)
{
    if (i < 0 || i >= adj.size() || j < 0 || j >= adj[0].size() || vis[i][j] || adj[i][j] == '-')
        return 0;

    vis[i][j] = true;

    return 1 + dfs(adj, vis, i + 1, j) + dfs(adj, vis, i - 1, j) + dfs(adj, vis, i, j + 1) + dfs(adj, vis, i, j - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adj_mat(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> adj_mat[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int minArea = INT_MAX;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && adj_mat[i][j] == '.')
                minArea = min(dfs(adj_mat, visited, i, j), minArea);

    if (minArea != INT_MAX)
        cout << minArea << endl;
    else
        cout << -1 << endl;

    return 0;
}