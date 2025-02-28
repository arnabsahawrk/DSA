#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, grpSize;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        grpSize.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            grpSize[i] = 1;
        }
    }

    int disjointFind(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = disjointFind(parent[node]);
    }

    void disjointUnion(int u, int v)
    {
        int parentU = disjointFind(u);
        int parentV = disjointFind(v);

        if (parentU == parentV)
            return;

        if (grpSize[parentU] >= grpSize[parentV])
        {
            parent[parentV] = parentU;
            grpSize[parentU] += grpSize[parentV];
        }
        else
        {
            parent[parentU] = parentV;
            grpSize[parentV] += grpSize[parentU];
        }
    }
};

int main()
{
    int N, E, cycles = 0;
    cin >> N >> E;

    DisjointSet dsu(N);

    while (E--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (dsu.disjointFind(u) == dsu.disjointFind(v))
            cycles++;
        else
            dsu.disjointUnion(u, v);
    }

    cout << cycles << endl;

    return 0;
}