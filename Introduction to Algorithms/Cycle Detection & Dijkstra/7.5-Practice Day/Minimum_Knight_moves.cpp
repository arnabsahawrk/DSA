// https://www.spoj.com/problems/NAKANJ/
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, pair<int, int> src)
{
    vector<vector<bool>> vis(8, vector<bool>(8, false));
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

            bool valid = (nRow >= 0 && nRow < 8) && (nCol >= 0 && nCol < 8);

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
        string source, destination;
        cin >> source >> destination;

        int srcRow = source[0] - 'a';
        int srcCol = source[1] - '1';

        int desRow = destination[0] - 'a';
        int desCol = destination[1] - '1';

        vector<vector<int>> adj_mat(8, vector<int>(8, 0));
        bfs(adj_mat, {srcRow, srcCol});

        cout << adj_mat[desRow][desCol] << endl;
    }

    return 0;
}