#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    list<int> l1(10);
    list<int> l2(10, 3);
    list<int> l3 = {1, 2, 3, 4, 5};
    list<int> l4(l2);
    vector<int> v = {10, 40, 99};
    list<int> l5(v.begin(), v.end());

    cout << l1.size() << endl;
    cout << *l2.begin() << endl;

    for (int value : l3)
    {
        cout << value << " ";
    }
    cout << endl;

    for (auto it = l4.begin(); it != l4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto value : l5)
    {
        cout << value << " ";
    }
    return 0;
}