// https://cses.fi/problemset/task/1672/
#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<long long int>> &adj_mat)
{
    int v = adj_mat.size();

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long int>> adj_mat(n, vector<long long int>(n, LLONG_MAX));
    for (int i = 0; i < n; i++)
        adj_mat[i][i] = 0;

    while (m--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj_mat[u][v] = min(adj_mat[u][v], w);
        adj_mat[v][u] = min(adj_mat[v][u], w);
    }

    floyd_warshall(adj_mat);

    while (q--)
    {
        int s, d;
        cin >> s >> d;
        s--;
        d--;

        if (adj_mat[s][d] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[s][d] << endl;
    }

    return 0;
}