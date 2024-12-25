#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {1, 2, 3};
    list<int> l1 = {7, 7, 7, 4, 5, 6};
    list<int> l2;
    l2.assign(l.begin(), l.end());
    l2 = l;

    l2.pop_front();
    l2.pop_back();

    l2.push_back(7);
    l2.push_front(8);

    cout << *next(l2.begin(), 2) << endl;
    l2.insert(next(l2.begin(), 2), 100);
    l2.insert(next(l2.begin(), 2), l1.begin(), l1.end());

    l2.erase(next(l2.begin(), 8));
    l2.erase(next(l2.begin(), 6), next(l2.begin(), 8));

    replace(l2.begin(), l2.end(), 7, 100);

    auto it = find(l2.begin(), l2.end(), 4);

    if (it == l2.end())
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << "FOUND" << endl;
    }

    for (auto value : l2)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}