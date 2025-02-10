/*
Given a graph in 2D matrix , Answer the Following Questions.

5 8
~~~~~~~~
~..~...~
~~~~.~.~
~..~...~
~~~~~~~~

Here '.' indicates cities and '~' indicates river.

1. Counting number of countries in the Matrix
2. Determine if we could go from one city to another by vehicle
3. Number of max cities in the MAP
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> adj_mat, vector<vector<bool>> &visited, int row, int col, int numbOfRow, int numbOfCol, int &cities)
{
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    visited[row][col] = true;
    cities++;

    for (int i = 0; i < 4; i++)
    {
        int rowC = row + direction[i].first;
        int colC = col + direction[i].second;

        bool valid = (rowC >= 0 && rowC < numbOfRow) && (colC >= 0 && colC < numbOfCol);

        if (valid && !visited[rowC][colC] && adj_mat[rowC][colC] != '~')
            dfs(adj_mat, visited, rowC, colC, numbOfRow, numbOfCol, cities);
    }
}

bool bfs(vector<vector<char>> adj_mat, int srcI, int srcJ, int desI, int desJ, int numbOfRow, int numbOfCol)
{
    vector<vector<bool>> visited(numbOfRow, vector<bool>(numbOfCol, false));
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    visited[srcI][srcJ] = true;

    queue<pair<int, int>> q;
    q.push({srcI, srcJ});

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int childI = parent.first + direction[i].first;
            int childJ = parent.second + direction[i].second;

            bool valid = (childI >= 0 && childI < numbOfRow) && (childJ >= 0 && childJ < numbOfCol);

            if (valid && !visited[childI][childJ] && adj_mat[childI][childJ] != '~')
            {
                q.push({childI, childJ});
                visited[childI][childJ] = true;
            }
        }
    }

    return visited[desI][desJ];
}

void result(vector<vector<char>> adj_mat, int row, int col)
{
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    int countries = 0;
    int cities = 0;
    int maxCities = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!visited[i][j] && adj_mat[i][j] != '~')
            {
                dfs(adj_mat, visited, i, j, row, col, cities);
                countries++;
                maxCities = max(cities, maxCities);
                cities = 0;
            }
        }
    }

    // 1. Counting number of countries in the Matrix
    cout << "Number of connected countries: " << countries << endl;

    cout << endl;

    // 2. Determine if we could go from one city to another by vehicle
    int srcI, srcJ, desI, desJ;
    cin >> srcI >> srcJ >> desI >> desJ;

    if (bfs(adj_mat, srcI, srcJ, desI, desJ, row, col))
        cout << "Yes; we could go from one city to another by vehicle" << endl;
    else
        cout << "No; we could go from one city to another by vehicle" << endl;

    cout << endl;

    // 3. Number of max cities in the MAP
    cout << "Number of connected max cities: " << maxCities << endl;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<char>> adjacency_matrix(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> adjacency_matrix[i][j];
        }
    }

    result(adjacency_matrix, row, col);

    return 0;
}