// https://cses.fi/problemset/task/1676
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, grpSize;
    int maxGrpSize = 1;

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

    int disjointUnion(int u, int v)
    {
        int parentU = disjointFind(u);
        int parentV = disjointFind(v);

        maxGrpSize = max({maxGrpSize, grpSize[parentU], grpSize[parentV]});

        if (parentU == parentV)
            return maxGrpSize;

        if (grpSize[parentU] >= grpSize[parentV])
        {
            parent[parentV] = parentU;
            grpSize[parentU] += grpSize[parentV];
            maxGrpSize = max(grpSize[parentU], maxGrpSize);
        }
        else
        {
            parent[parentU] = parentV;
            grpSize[parentV] += grpSize[parentU];
            maxGrpSize = max(grpSize[parentV], maxGrpSize);
        }

        return maxGrpSize;
    }
};

int main()
{
    int cities, roads;
    cin >> cities >> roads;

    DisjointSet components(cities);
    int numberOfComponents = cities, largestComponents = 1;

    while (roads--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int parentU = components.disjointFind(u);
        int parentV = components.disjointFind(v);

        if (parentU != parentV)
        {
            largestComponents = components.disjointUnion(u, v);
            numberOfComponents--;
        }
        cout << numberOfComponents << " " << largestComponents << endl;
    }

    return 0;
}