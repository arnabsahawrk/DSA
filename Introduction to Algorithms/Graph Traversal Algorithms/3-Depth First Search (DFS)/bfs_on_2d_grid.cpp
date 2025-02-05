#include <bits/stdc++.h>
using namespace std;

void bfs_on_2d_grid(int si, int sj, int row, int col) // O(row * col)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> moved = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// for 4 child

    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        cout << parent.first << " " << parent.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + moved[i].first;
            int cj = parent.second + moved[i].second;

            bool valid = (ci >= 0 && ci < row) && (cj >= 0 && cj < col);

            if (valid && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
            }
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<char>> grid(row, vector<char>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    int src_i, src_j;
    cin >> src_i >> src_j;

    bfs_on_2d_grid(src_i, src_j, row, col);
    return 0;
}