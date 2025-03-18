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

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool compareFunc(Edge l, Edge r) { return l.c < r.c; }

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), compareFunc);

    DisjointSet dsu(n);

    int totalCost = 0;
    for (auto ed : edge_list)
    {
        int parA = dsu.disjointFind(ed.a);
        int parB = dsu.disjointFind(ed.b);

        if (parA != parB)
        {
            dsu.disjointUnion(ed.a, ed.b);
            totalCost += ed.c;
        }
    }

    cout << totalCost << endl;

    return 0;
}