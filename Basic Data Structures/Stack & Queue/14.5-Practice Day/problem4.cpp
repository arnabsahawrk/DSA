#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    int t;
    cin >> t;

    while (t--)
    {
        int value;
        cin >> value;

        q.push(value);

        int s = q.size();

        while (--s)
        {
            q.push(q.front());
            q.pop();
        }
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}