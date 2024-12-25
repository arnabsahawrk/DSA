#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {1, 2, 3, 4, 5};

    cout << l.front() << endl;
    cout << l.back() << endl;
    cout << *next(l.begin(), 2);
    return 0;
}