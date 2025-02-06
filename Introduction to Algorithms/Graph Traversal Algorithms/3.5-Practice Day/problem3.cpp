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
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
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

            pq.push(count);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}