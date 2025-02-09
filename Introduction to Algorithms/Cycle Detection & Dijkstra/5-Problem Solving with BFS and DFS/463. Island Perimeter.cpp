// https://leetcode.com/problems/island-perimeter/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        pair<int, int> firstLand = {-1, -1};

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    firstLand = {i, j};
                    break;
                }
            }

            if (firstLand.first != -1)
                break;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        return dfs(grid, visited, firstLand.first, firstLand.second);
    }

private:
    int dfs(vector<vector<int>> &g, vector<vector<bool>> &v, int i, int j)
    {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] == 0)
            return 1;

        if (v[i][j])
            return 0;

        v[i][j] = true;

        return dfs(g, v, i + 1, j) + dfs(g, v, i - 1, j) + dfs(g, v, i, j + 1) + dfs(g, v, i, j - 1);
    }
};