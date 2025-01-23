// https://codeforces.com/problemset/problem/22/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    set<int> s;

    while (t--)
    {
        int value;
        cin >> value;

        s.insert(value);
    }

    if (s.size() < 2)
        cout << "NO" << endl;
    else
        cout << *(++s.begin()) << endl;

    return 0;
}