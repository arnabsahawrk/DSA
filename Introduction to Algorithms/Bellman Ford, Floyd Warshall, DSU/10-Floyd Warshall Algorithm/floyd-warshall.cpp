#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &adj_mat)
{
    int v = adj_mat.size();

    for (int k = 0; k < v; k++) // O(V)
    {
        for (int i = 0; i < v; i++) // O(V)
        {
            for (int j = 0; j < v; j++) // O(V)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX)
                    if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }
} // Time Complexity: O(V^3)

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjacency_matrix(vertices, vector<int>(vertices));
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i == j)
                adjacency_matrix[i][j] = 0;
            else
                adjacency_matrix[i][j] = INT_MAX;
        }
    }

    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjacency_matrix[u][v] = w;
    }

    floyd_warshall(adjacency_matrix);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adjacency_matrix[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adjacency_matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}