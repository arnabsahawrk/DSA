#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ll;
    int query;
    cin >> query;

    while (query--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            ll.emplace_front(v);
        }
        else if (x == 1)
        {
            ll.emplace_back(v);
        }
        else
        {
            int sz = ll.size();

            if (v >= 0 && v < sz)
            {
                auto it = next(ll.begin(), v);
                ll.erase(it);
            }
        }

        cout << "L -> ";
        for (auto it = ll.begin(); it != ll.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        cout << "R -> ";
        for (auto it = ll.rbegin(); it != ll.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}