// Let's say for a graph we have connected the nodes with edges. How to determine if all the node got connected or not?
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
    int vertices, edges;
    cin >> vertices >> edges;

    DisjointSet dsu(vertices);

    while (edges--)
    {
        int u, v;
        cin >> u >> v;

        dsu.disjointUnion(u, v);
    }

    bool isConnected = true;

    for (int i = 1; i < vertices; i++)
    {
        if (dsu.disjointFind(0) != dsu.disjointFind(i))
        {
            isConnected = false;
            break;
        }
    }

    if (isConnected)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}