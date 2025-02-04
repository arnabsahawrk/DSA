#include <bits/stdc++.h>
using namespace std;

vector<int> levelNodes(vector<vector<int>> adj_list, int L)
{
    int len = adj_list.size();
    vector<bool> visited(len, false);
    vector<int> level(len, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    level[0] = 0;

    vector<int> levelValues;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj_list[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[parent] + 1;

                if (level[child] == L)
                    levelValues.push_back(child);
            }
        }
    }

    sort(levelValues.begin(), levelValues.end(), greater<int>());

    return levelValues;
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices + 1);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int L;
    cin >> L;

    vector<int> levelValues = levelNodes(adj_list, L);

    for (int x : levelValues)
        cout << x << " ";

    return 0;
}