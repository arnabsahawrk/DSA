// https://leetcode.com/problems/number-of-enclaves/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
        {
            if (!vis[i][col - 1] && grid[i][col - 1])
                dfs(grid, vis, i, col - 1);

            if (!vis[i][0] && grid[i][0])
                dfs(grid, vis, i, 0);
        }

        for (int i = 0; i < col; i++)
        {
            if (!vis[0][i] && grid[0][i])
                dfs(grid, vis, 0, i);

            if (!vis[row - 1][i] && grid[row - 1][i])
                dfs(grid, vis, row - 1, i);
        }

        int moves = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (!vis[i][j] && grid[i][j])
                    moves++;

        return moves;
    }

private:
    void dfs(vector<vector<int>> &g, vector<vector<bool>> &v, int i, int j)
    {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || v[i][j] || !g[i][j])
            return;

        v[i][j] = true;

        dfs(g, v, i + 1, j);
        dfs(g, v, i - 1, j);
        dfs(g, v, i, j + 1);
        dfs(g, v, i, j - 1);
    }
};