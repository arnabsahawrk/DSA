#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    int value;
    while (cin >> value)
    {
        q.push(value);
    }

    while (!q.empty())
    {
        cout << "Size: " << q.size() << endl;
        cout << q.front() << " " << q.back() << endl;
        cout << endl;

        q.pop();
    }

    cout << "Size: " << q.size() << endl;

    return 0;
}