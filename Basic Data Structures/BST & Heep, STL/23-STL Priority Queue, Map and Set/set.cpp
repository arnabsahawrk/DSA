#include <bits/stdc++.h>
using namespace std;

int main()
{
    // set use balanced BST mechanism under the hood. mean store in sorted order and not contain duplicate
    set<int> s;

    int value;
    while (cin >> value)
        s.insert(value); // O(logN)

    for (auto it : s)
        cout << it << " ";

    cout << endl;

    for (auto it = s.rbegin(); it != s.rend(); it++)
        cout << *it << " ";

    cout << endl;

    if (s.count(30)) // O(logN)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}