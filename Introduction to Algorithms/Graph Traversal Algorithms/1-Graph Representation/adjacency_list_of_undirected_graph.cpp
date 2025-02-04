#include <bits/stdc++.h>
using namespace std;

int main()
{
    // best for all the connected nodes from a node
    int nodes, edges;
    cin >> nodes >> edges; // input number of nodes and connection

    vector<int> adj_list[nodes]; // create an array of vector for represent the graph

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b); // join the connection to keep its node number
        adj_list[b].push_back(a); // for undirected graph
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";

        for (int x : adj_list[i])
            cout << x << " ";

        cout << endl;
    }

    return 0;
}