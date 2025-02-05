#include <bits/stdc++.h>
using namespace std;

void dfs_on_2d_grid(vector<vector<bool>> &visited, int si, int sj, int row, int col) //O(row * col)
{
    cout << si << " " << sj << endl;
    ;
    visited[si][sj] = true;
    vector<pair<int, int>> moved = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // for 4 child

    for (int i = 0; i < 4; i++)
    {
        int ci = si + moved[i].first;
        int cj = sj + moved[i].second;

        bool valid = (ci >= 0 && ci < row) && (cj >= 0 && cj < col);

        if (valid && !visited[ci][cj])
            dfs_on_2d_grid(visited, ci, cj, row, col);
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

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int si, sj;
    cin >> si >> sj;

    dfs_on_2d_grid(visited, si, sj, row, col);
    return 0;
}