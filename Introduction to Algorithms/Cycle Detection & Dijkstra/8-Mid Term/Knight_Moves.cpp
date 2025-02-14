#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, pair<int, int> src)
{
    int row = adj.size();
    int col = adj[0].size();

    vector<vector<bool>> vis(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    int knightRow[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int knightCol[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    q.push({src.first, src.second});
    vis[src.first][src.second] = true;
    adj[src.first][src.second] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nRow = p.first + knightRow[i];
            int nCol = p.second + knightCol[i];

            bool valid = (nRow >= 0 && nRow < row) && (nCol >= 0 && nCol < col);

            if (valid && !vis[nRow][nCol])
            {
                vis[nRow][nCol] = true;
                adj[nRow][nCol] = adj[p.first][p.second] + 1;
                q.push({nRow, nCol});
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int row, col, srcI, srcJ, desI, desJ;
        cin >> row >> col >> srcI >> srcJ >> desI >> desJ;

        vector<vector<int>> adj_mat(row, vector<int>(col, -1));
        bfs(adj_mat, {srcI, srcJ});

        cout << adj_mat[desI][desJ] << endl;
    }

    return 0;
}