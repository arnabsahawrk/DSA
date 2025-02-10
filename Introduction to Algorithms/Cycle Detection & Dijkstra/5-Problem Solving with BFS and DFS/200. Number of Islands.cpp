// https://leetcode.com/problems/number-of-islands/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();

        int numberOfIslands = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, r, c);
                    numberOfIslands++;
                }
            }
        }

        return numberOfIslands;
    }

private:
    void dfs(vector<vector<char>> &g, int i, int j, int r, int c)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || g[i][j] == '0')
            return;

        g[i][j] = '0';

        dfs(g, i - 1, j, r, c);
        dfs(g, i + 1, j, r, c);
        dfs(g, i, j - 1, r, c);
        dfs(g, i, j + 1, r, c);
    }
};