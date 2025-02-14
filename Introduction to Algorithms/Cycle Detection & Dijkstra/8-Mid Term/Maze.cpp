#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> &maze, vector<vector<bool>> &visited, vector<vector<pair<int, int>>> &parent, pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    parent[src.first][src.second] = {-1, -1};

    int dRow[] = {0, 0, -1, 1};
    int dCol[] = {1, -1, 0, 0};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dRow[i];
            int nc = c + dCol[i];

            bool valid = (nr >= 0 && nr < maze.size() && nc >= 0 && nc < maze[0].size());

            if (valid && !visited[nr][nc] && maze[nr][nc] != '#')
            {
                visited[nr][nc] = true;
                parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<char>> maze(row, vector<char>(col));
    int srcI, srcJ, desI, desJ;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                srcI = i;
                srcJ = j;
            }
            else if (maze[i][j] == 'D')
            {
                desI = i;
                desJ = j;
            }
        }
    }

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<vector<pair<int, int>>> parent(row, vector<pair<int, int>>(col, {-1, -1}));

    bfs(maze, visited, parent, {srcI, srcJ});

    if (visited[desI][desJ])
    {
        int r = desI, c = desJ;
        while (!(r == srcI && c == srcJ))
        {
            if (maze[r][c] != 'R' && maze[r][c] != 'D')
                maze[r][c] = 'X';

            pair<int, int> par = parent[r][c];
            r = par.first;
            c = par.second;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << maze[i][j];
        cout << endl;
    }

    return 0;
}
