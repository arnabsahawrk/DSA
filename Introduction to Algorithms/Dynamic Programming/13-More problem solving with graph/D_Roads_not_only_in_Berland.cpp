// https://codeforces.com/problemset/problem/25/D
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, groupSize;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        groupSize.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int disjointFind(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = disjointFind(parent[node]);
    }

    void disjointUnion(int u, int v)
    {
        int parentU = disjointFind(u);
        int parentV = disjointFind(v);
        if (parentU == parentV)
            return;

        if (groupSize[parentU] >= groupSize[parentV])
        {
            parent[parentV] = parentU;
            groupSize[parentU] += groupSize[parentV];
        }
        else
        {
            parent[parentU] = parentV;
            groupSize[parentV] += groupSize[parentU];
        }
    }
};

int main()
{
    int n;
    cin >> n;

    DisjointSet dsu(n);

    vector<pair<int, int>> redundant_edges;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (dsu.disjointFind(u) != dsu.disjointFind(v))
            dsu.disjointUnion(u, v);
        else
            redundant_edges.push_back({u + 1, v + 1});
    }

    vector<int> ultimate_parents;
    for (int i = 0; i < n; i++)
        if (dsu.disjointFind(i) == i)
            ultimate_parents.push_back(i + 1);

    cout << ultimate_parents.size() - 1 << endl;

    for (int k = 0; k < ultimate_parents.size() - 1; k++)
    {
        int i = ultimate_parents[k];
        int j = ultimate_parents[k + 1];

        auto [u, v] = redundant_edges.back();
        redundant_edges.pop_back();

        cout << u << " " << v << " " << i << " " << j << endl;
    }

    return 0;
}