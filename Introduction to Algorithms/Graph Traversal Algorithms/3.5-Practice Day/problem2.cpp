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

    vector<bool> visited(vertices, false);
    int components = 0;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            components++;

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
                    }
                }
            }
        }
    }

    cout << components << endl;

    return 0;
}