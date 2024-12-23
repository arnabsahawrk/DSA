#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l(10, 5);

    l.clear();
    cout << l.size() << endl;
    cout << l.max_size() << endl;
    cout << l.empty() << endl;
    l.resize(5);
    cout << l.size() << endl;

    for (int val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    list<int> l2 = {1, 2, 3};
    l2.resize(5, 100);
    for (int val : l2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}