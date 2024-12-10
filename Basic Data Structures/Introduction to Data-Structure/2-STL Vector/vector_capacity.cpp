#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    cout << v.size() << endl;

    cout << v.capacity() << endl; // vector double its capacity every time when it reach its size.

    cout << v.max_size() << endl;

    v.clear(); // clear only do the size 0 but it doesn't clear the value

    cout << v.empty() << endl;

    v.resize(7);
    v.resize(10, 100);

    return 0;
}