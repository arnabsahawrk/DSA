#include <bits/stdc++.h>
using namespace std;

int main()
{
    // best for when work with the edges
    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<int, int>> edge_list;

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        edge_list.push_back({a, b});
    }

    for (pair<int, int> x : edge_list)
        cout << x.first << " " << x.second << endl;

    return 0;
}