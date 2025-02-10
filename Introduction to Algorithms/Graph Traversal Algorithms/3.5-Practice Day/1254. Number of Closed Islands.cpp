// https://leetcode.com/problems/number-of-closed-islands/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int closedIslands = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool isClosed = true;

                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();

                        if (p.first == 0 || p.second == 0 || p.first == row - 1 || p.second == col - 1)
                            isClosed = false;

                        for (int i = 0; i < 4; i++)
                        {
                            int ci = p.first + dir[i].first;
                            int cj = p.second + dir[i].second;

                            bool valid = (ci >= 0 && ci < row) && (cj >= 0 && cj < col);

                            if (valid && !visited[ci][cj] && grid[ci][cj] == 0)
                            {
                                q.push({ci, cj});
                                visited[ci][cj] = true;
                            }
                        }
                    }

                    if (isClosed)
                        closedIslands++;
                }
            }
        }

        return closedIslands;
    }
};