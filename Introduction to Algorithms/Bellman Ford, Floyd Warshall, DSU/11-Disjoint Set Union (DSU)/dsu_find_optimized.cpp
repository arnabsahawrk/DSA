#include <bits/stdc++.h>
using namespace std;

int dsu_find(vector<int> &v, int node) // O(logN)
{
    if (v[node] == -1)
        return node;

    int leader = dsu_find(v, v[node]);
    v[node] = leader;
    return leader;
}

int main()
{
    vector<int> par(6, -1);
    par[0] = 1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    cout << dsu_find(par, 4) << endl;

    for (int i = 0; i < 6; i++)
        cout << i << " -> " << par[i] << endl;
    return 0;
}