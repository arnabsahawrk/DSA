#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<long long>> &mat)
{
    int n = mat.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX)
                    mat[i][j] = min((mat[i][k] + mat[k][j]), mat[i][j]);
            }
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<long long>> mat(N, vector<long long>(N, LLONG_MAX));
    for (int i = 0; i < N; i++)
        mat[i][i] = 0;

    while (E--)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        mat[u][v] = min(mat[u][v], w);
    }

    floyd_warshall(mat);

    int query;
    cin >> query;

    while (query--)
    {
        int source, destination;
        cin >> source >> destination;
        source--, destination--;

        if (mat[source][destination] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << mat[source][destination] << endl;
    }

    return 0;
}