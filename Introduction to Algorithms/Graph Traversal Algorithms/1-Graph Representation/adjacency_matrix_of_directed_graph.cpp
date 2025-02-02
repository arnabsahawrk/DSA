#include <bits/stdc++.h>
using namespace std;

int main()
{
    // best for check 2 nodes are connected or not -> O(1)
    int nodes, edges;
    cin >> nodes >> edges; // input number of nodes and connection

    int adj_matrix[nodes][nodes];              // create a matrix for represent the graph
    memset(adj_matrix, 0, sizeof(adj_matrix)); // initially every nodes connection will 0

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            if (i == j)
                adj_matrix[i][j] = 1; // simillar nodes connected means 1 to 1, 4 to 4 connected

    for (int i = 0; i < edges; i++)
    {
        int row, col;
        cin >> row >> col;

        adj_matrix[row][col] = 1; // join the connection with 1
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}