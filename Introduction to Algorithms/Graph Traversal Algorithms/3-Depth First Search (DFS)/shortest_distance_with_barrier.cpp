#include <bits/stdc++.h>
using namespace std;

void shortest_distance_with_barrier(vector<vector<char>> grid, int si, int sj, int row, int col)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> moved = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> level(row, vector<int>(col, -1));

    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + moved[i].first;
            int cj = parent.second + moved[i].second;

            bool valid = (ci >= 0 && ci < row) && (cj >= 0 && cj < col);

            if (valid && !visited[ci][cj] && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[parent.first][parent.second] + 1;
            }
        }
    }

    int i, j;
    cin >> i >> j;

    cout << level[i][j] << endl;
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

    shortest_distance_with_barrier(grid, src_i, src_j, row, col);
    return 0;
}