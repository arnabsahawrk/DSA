// https://leetcode.com/problems/flood-fill/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int row = image.size();
        int col = image[0].size();
        int startingColor = image[sr][sc];

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        image[sr][sc] = color;
        visited[sr][sc] = true;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            pair<int, int> par = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int cI = par.first + dir[i].first;
                int cJ = par.second + dir[i].second;

                bool valid = (cI >= 0 && cI < row) && (cJ >= 0 && cJ < col);

                if (valid && !visited[cI][cJ] && image[cI][cJ] == startingColor)
                {
                    q.push({cI, cJ});
                    image[cI][cJ] = color;
                    visited[cI][cJ] = true;
                }
            }
        }

        return image;
    }
};