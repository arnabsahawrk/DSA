#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int n;
    cin >> n;

    vector<bool> visited(vertices, false);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    int count = 1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int c : adj_list[p])
        {
            if (!visited[c])
            {
                q.push(c);
                visited[c] = true;
                count++;
            }
        }
    }

    cout << count;

    return 0;
}