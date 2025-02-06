#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> bMap, int h, int w)
{
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int count = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (!visited[i][j] && bMap[i][j] != '#')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                count++;

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int cI = p.first + dir[i].first;
                        int cJ = p.second + dir[i].second;

                        bool valid = (cI >= 0 && cI < h) && (cJ >= 0 && cJ < w);

                        if (valid && !visited[cI][cJ] && bMap[cI][cJ] != '#')
                        {
                            q.push({cI, cJ});
                            visited[cI][cJ] = true;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;
}

int main()
{
    int height, width;
    cin >> height >> width;

    vector<vector<char>> buildingMap(height, vector<char>(width));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> buildingMap[i][j];
        }
    }

    bfs(buildingMap, height, width);

    return 0;
}