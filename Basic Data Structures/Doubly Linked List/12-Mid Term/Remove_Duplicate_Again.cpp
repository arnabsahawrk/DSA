#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ll;

    int value;
    while (cin >> value && value != -1)
    {
        ll.emplace_back(value);
    }

    ll.sort();
    ll.unique();

    for (auto val : ll)
    {
        cout << val << " ";
    }

    return 0;
}