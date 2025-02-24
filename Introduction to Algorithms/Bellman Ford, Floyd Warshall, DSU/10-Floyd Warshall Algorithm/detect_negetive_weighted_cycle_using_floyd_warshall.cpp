#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(vector<vector<int>> &adj_mat)
{
    int v = adj_mat.size();

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX)
                    if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    for (int i = 0; i < v; i++)
        if (adj_mat[i][i] != 0)
            return true;

    return false;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_mat(vertices, vector<int>(vertices));
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_mat[u][v] = w;
    }

    bool isCycle = cycle_detection(adj_mat);

    if (isCycle)
        cout << "Negative Weighted Cycle Detected" << endl;
    else
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adj_mat[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << adj_mat[i][j] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}