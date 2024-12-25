#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {1, 2, 9, 7, 2, 20, 5, 9, 2, 1, 3, 4, 5, 20, 20, 20};

    l.sort();
    l.sort(greater<int>());

    l.remove(20);

    l.unique(); // for sorted list

    l.reverse();

    for (auto value : l)
    {
        cout << value << " ";
    }
    return 0;
}