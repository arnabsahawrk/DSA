// https://leetcode.com/problems/count-sub-islands/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid2.size();
        int n = grid2[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int numberOfSubIslands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid2[i][j])
                {
                    bool isSub = true;
                    dfs(grid1, grid2, visited, i, j, isSub);
                    if (isSub)
                        numberOfSubIslands++;
                }
            }
        }

        return numberOfSubIslands;
    }

private:
    void dfs(vector<vector<int>> &g1, vector<vector<int>> &g2, vector<vector<bool>> &v, int i, int j, bool &flag)
    {
        if (i < 0 || i >= g2.size() || j < 0 || j >= g2[0].size() || v[i][j] || !g2[i][j])
            return;

        v[i][j] = true;
        if (g1[i][j] == 0)
            flag = false;

        dfs(g1, g2, v, i + 1, j, flag);
        dfs(g1, g2, v, i - 1, j, flag);
        dfs(g1, g2, v, i, j + 1, flag);
        dfs(g1, g2, v, i, j - 1, flag);
    }
};