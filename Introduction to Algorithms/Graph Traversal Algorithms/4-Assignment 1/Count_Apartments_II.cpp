#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>> aparment, vector<int> &count, int row, int col)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!visited[i][j] && aparment[i][j] != '#')
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int c = 0;

                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    c++;

                    for (int i = 0; i < 4; i++)
                    {
                        int cI = p.first + dir[i].first;
                        int cJ = p.second + dir[i].second;

                        bool valid = (cI >= 0 && cI < row) && (cJ >= 0 && cJ < col);

                        if (valid && !visited[cI][cJ] && aparment[cI][cJ] != '#')
                        {
                            q.push({cI, cJ});
                            visited[cI][cJ] = true;
                        }
                    }
                }

                count.push_back(c);
            }
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<char>> aparment(row, vector<char>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> aparment[i][j];
        }
    }

    vector<int> countApartment;

    bfs(aparment, countApartment, row, col);

    if (countApartment.empty())
        cout << 0;
    else
    {
        sort(countApartment.begin(), countApartment.end());

        for (int x : countApartment)
            cout << x << " ";
    }

    return 0;
}