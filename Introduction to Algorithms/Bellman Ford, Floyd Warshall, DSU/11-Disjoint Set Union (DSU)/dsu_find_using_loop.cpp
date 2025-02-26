#include <bits/stdc++.h>
using namespace std;

int dsu_find(vector<int> v, int node) // O(N)
{
    while (v[node] != -1)
        node = v[node];

    return node;
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
    return 0;
}