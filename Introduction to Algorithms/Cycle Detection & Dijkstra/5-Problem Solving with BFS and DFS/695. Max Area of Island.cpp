// https://leetcode.com/problems/max-area-of-island/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int mx = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && grid[i][j])
                    mx = max(dfs(grid, visited, i, j), mx);

        return mx;
    }

private:
    int dfs(vector<vector<int>> &g, vector<vector<bool>> &v, int i, int j)
    {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || v[i][j] || g[i][j] == 0)
            return 0;

        v[i][j] = true;

        return 1 + dfs(g, v, i + 1, j) + dfs(g, v, i - 1, j) + dfs(g, v, i, j + 1) + dfs(g, v, i, j - 1);
    }
};