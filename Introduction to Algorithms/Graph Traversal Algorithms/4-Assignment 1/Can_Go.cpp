#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> bMap, int srcI, int srcJ, int desI, int desJ, int h, int w)
{
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    visited[srcI][srcJ] = true;

    queue<pair<int, int>> q;
    q.push({srcI, srcJ});

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

    if (visited[desI][desJ])
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    int height, width;
    cin >> height >> width;

    vector<vector<char>> buildingMap(height, vector<char>(width));
    int aI = 0, aJ = 0, bI = 0, bJ = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> buildingMap[i][j];
            if (buildingMap[i][j] == 'A')
            {
                aI = i;
                aJ = j;
            }
            else if (buildingMap[i][j] == 'B')
            {
                bI = i;
                bJ = j;
            }
        }
    }

    bfs(buildingMap, aI, aJ, bI, bJ, height, width);

    return 0;
}