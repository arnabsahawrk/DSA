#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &adj, vector<vector<bool>> &vis, int srcN, int srcM, int desN, int desM)
{
    if (srcN < 0 || srcN >= adj.size() || srcM < 0 || srcM >= adj[0].size() || vis[srcN][srcM] || adj[srcN][srcM] == '-')
        return false;

    vis[srcN][srcM] = true;

    if (vis[desN][desM])
        return true;

    return dfs(adj, vis, srcN + 1, srcM, desN, desM) || dfs(adj, vis, srcN - 1, srcM, desN, desM) || dfs(adj, vis, srcN, srcM + 1, desN, desM) || dfs(adj, vis, srcN, srcM - 1, desN, desM);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> adj_mat(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> adj_mat[i][j];

    int srcN, srcM, desN, desM;
    cin >> srcN >> srcM >> desN >> desM;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    if (dfs(adj_mat, visited, srcN, srcM, desN, desM))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}