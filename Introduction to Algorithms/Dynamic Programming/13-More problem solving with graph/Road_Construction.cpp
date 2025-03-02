// https://cses.fi/problemset/task/1676/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, groupSize;
    int maxGrpSize = 1;

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

    int disjointUnion(int u, int v)
    {
        int parentU = disjointFind(u);
        int parentV = disjointFind(v);

        maxGrpSize = max({groupSize[parentU], groupSize[parentV], maxGrpSize});

        if (parentU == parentV)
            return maxGrpSize;

        if (groupSize[parentU] >= groupSize[parentV])
        {
            parent[parentV] = parentU;
            groupSize[parentU] += groupSize[parentV];
            maxGrpSize = max(groupSize[parentU], maxGrpSize);
        }
        else
        {
            parent[parentU] = parentV;
            groupSize[parentV] += groupSize[parentU];
            maxGrpSize = max(groupSize[parentV], maxGrpSize);
        }

        return maxGrpSize;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DisjointSet dsu(n);
    int components = n, maxGrpSize = 1;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int parentU = dsu.disjointFind(u);
        int parentV = dsu.disjointFind(v);

        if (parentU != parentV)
        {
            maxGrpSize = dsu.disjointUnion(u, v);
            components--;
        }

        cout << components << " " << maxGrpSize << endl;
    }

    return 0;
}