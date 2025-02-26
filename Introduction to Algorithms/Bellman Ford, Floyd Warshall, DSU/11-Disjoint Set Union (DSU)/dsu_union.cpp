#include <bits/stdc++.h>
using namespace std;

int dsu_find(vector<int> &v, int node)
{
    if (v[node] == -1)
        return node;

    int leader = dsu_find(v, v[node]);
    v[node] = leader;

    return leader;
}

void dsu_union(vector<int> &v, vector<int> &sz, int node1, int node2)
{
    int leader1 = dsu_find(v, node1); // O(logN)
    int leader2 = dsu_find(v, node2); // O(logN)   after a many times if we call dsu_find it becomes constant time so, we can say its time complexity   O(α(N)) -> alpha N

    if (sz[leader1] >= sz[leader2])
    {
        v[leader2] = leader1;
        sz[leader1] += sz[leader2];
    }
    else
    {
        v[leader1] = leader2;
        sz[leader2] += sz[leader1];
    }
}

int main()
{
    vector<int> par(6, -1);
    vector<int> group_size(6, 1);

    dsu_union(par, group_size, 1, 2);
    dsu_union(par, group_size, 0, 2);
    dsu_union(par, group_size, 3, 4);
    dsu_union(par, group_size, 4, 5);
    dsu_union(par, group_size, 1, 5);

    for (int v : group_size)
        cout << v << " ";

    cout << endl;

    for (int i = 0; i < 6; i++)
        cout << i << " -> " << par[i] << endl;

    return 0;
}