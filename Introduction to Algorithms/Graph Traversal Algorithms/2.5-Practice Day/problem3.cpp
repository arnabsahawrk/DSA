#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj_list(vertices + 1);

    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int N;
    cin >> N;

    cout << adj_list[N].size() << endl;

    return 0;
}