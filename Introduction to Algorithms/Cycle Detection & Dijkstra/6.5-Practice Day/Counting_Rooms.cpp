// https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &mat, vector<vector<bool>> &vis, int row, int col)
{
    if (row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size() || vis[row][col] || mat[row][col] == '#')
        return;

    vis[row][col] = true;

    dfs(mat, vis, row + 1, col);
    dfs(mat, vis, row - 1, col);
    dfs(mat, vis, row, col + 1);
    dfs(mat, vis, row, col - 1);
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
    int countRooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && adj_mat[i][j] != '#')
            {
                dfs(adj_mat, visited, i, j);
                countRooms++;
            }
        }
    }

    cout << countRooms << endl;
    return 0;
}