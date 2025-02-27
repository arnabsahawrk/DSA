// https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, grpSize; // initialize the parent and group size array

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);  // 1-indexed
        grpSize.resize(n + 1); // 1-indexed

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;  // initially all are the parent of themselves
            grpSize[i] = 1; // initially every every group has one node (themselve)
        }
    }

    int DisjointFind(int node)
    {
        if (node == parent[node]) // if found a node is its parent return the node
            return node;

        return parent[node] = DisjointFind(parent[node]); // when backtracking set ultimate parent for optimization
    }

    void DisjointUnion(int u, int v)
    {
        int parentU = DisjointFind(u);
        int parentV = DisjointFind(v);

        if (parentU == parentV) // when the parent is same that means they are in the same group
            return;

        if (grpSize[parentU] >= grpSize[parentV]) // join two groups based on size
        {
            parent[parentV] = parentU;            // now the small group ultimate parent is large group ultimate parent
            grpSize[parentU] += grpSize[parentV]; // increase the large group size
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

    DisjointSet roads(vertices);

    while (edges--)
    {
        int u, v;
        cin >> u >> v;

        roads.DisjointUnion(u, v);
    }

    vector<int> result;

    for (int i = 1; i <= vertices; i++)
    {
        if (roads.DisjointFind(1) != roads.DisjointFind(i))
        {
            roads.DisjointUnion(1, i);
            result.push_back(i);
        }
    }

    cout << result.size() << endl;

    for (int connection : result)
        cout << '1' << " " << connection << endl;

    return 0;
}