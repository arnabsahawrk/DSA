// https://codeforces.com/problemset/problem/25/D
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, grpSize;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        grpSize.resize(n + 1);

        for (int i = 0; i <= n; i++)
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
    int n;
    cin >> n;

    DisjointSet berland(n);
    vector<pair<int, int>> redundant_edges;

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        if (berland.disjointFind(u) != berland.disjointFind(v))
            berland.disjointUnion(u, v);
        else
            redundant_edges.push_back({u, v});
    }

    vector<int> ultimate_parents;
    for (int i = 1; i <= n; i++)
    {
        if (berland.disjointFind(i) == i)
            ultimate_parents.push_back(i);
    }

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