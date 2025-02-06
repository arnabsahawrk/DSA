#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    int adj_mat[vertices][vertices];
    memset(adj_mat, 0, sizeof(adj_mat));

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_mat[a][b] = 1;
    }

    int query;
    cin >> query;

    while (query--)
    {
        int a, b;
        cin >> a >> b;

        if (adj_mat[a][b] == 1 || a==b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}