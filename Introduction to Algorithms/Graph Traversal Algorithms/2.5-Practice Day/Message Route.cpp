// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

void messageRoute(vector<vector<int>> adj_list)
{
    int len = adj_list.size();
    vector<bool> visited(len, false);
    vector<int> level(len, -1);
    vector<int> parentList(len, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    level[0] = 1;
    parentList[0] = 0;

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
                parentList[child] = parent;
            }
        }
    }

    if (visited[len - 1])
    {
        cout << level[len - 1] << endl;

        stack<int> st;
        for (int node = len - 1; node != 0; node = parentList[node])
            st.push(node);
        st.push(0);

        while (!st.empty())
        {
            cout << st.top() + 1 << " ";
            st.pop();
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int computers, connections;
    cin >> computers >> connections;

    vector<vector<int>> adj_list(computers);

    while (connections--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    messageRoute(adj_list);

    return 0;
}