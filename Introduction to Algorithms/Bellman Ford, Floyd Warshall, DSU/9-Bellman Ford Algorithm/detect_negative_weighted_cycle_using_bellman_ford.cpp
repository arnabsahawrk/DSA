#include <bits/stdc++.h>
using namespace std;

void detect_negative_weighted_cycle(vector<pair<pair<int, int>, int>> v, int source)
{
    int vertices = v.size();
    vector<int> des(vertices, INT_MAX);
    des[source] = 0;

    while (--vertices)
    {
        for (auto pr : v)
        {
            int a = pr.first.first, b = pr.first.second, c = pr.second;

            if (des[a] != INT_MAX && des[a] + c < des[b])
                des[b] = des[a] + c;
        }
    }

    bool cycle = false;
    for (auto pr : v)
    {
        int a = pr.first.first, b = pr.first.second, c = pr.second;

        if (des[a] != INT_MAX && des[a] + c < des[b])
        {

            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Weighted Cycle Detected" << endl;
    else
    {
        for (int i = 0; i < des.size(); i++)
            cout << i << " -> " << des[i] << endl;
    }
}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<pair<pair<int, int>, int>> edge_list;

    while (edges--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back({{a, b}, c});
    }

    detect_negative_weighted_cycle(edge_list, 0);

    return 0;
}