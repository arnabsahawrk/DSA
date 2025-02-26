#include <bits/stdc++.h>
using namespace std;

int dsu_find(vector<int> &par, int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par, par[node]);
    par[node] = leader;

    return leader;
}

void dsu_union(vector<int> &par, vector<int> &grpSz, int node1, int node2)
{
    int leader1 = dsu_find(par, node1);
    int leader2 = dsu_find(par, node2);

    if (grpSz[leader1] >= grpSz[leader2])
    {
        par[leader2] = leader1;
        grpSz[leader1] += grpSz[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grpSz[leader2] += grpSz[leader1];
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> parent(vertices, -1);
    vector<int> groupSize(vertices, 1);

    bool cycle = false;

    while (edges--)
    {
        int u, v;
        cin >> u >> v;

        int leaderA = dsu_find(parent, u);
        int leaderB = dsu_find(parent, v);

        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union(parent, groupSize, u, v);
    }

    if (cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}