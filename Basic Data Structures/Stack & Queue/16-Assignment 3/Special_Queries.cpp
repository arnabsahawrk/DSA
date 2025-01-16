#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    queue<string> q;

    while (t--)
    {
        int x;
        cin >> x;

        if (x)
        {
            if (q.empty())
                cout << "Invalid" << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else
        {
            string s;
            cin >> s;

            q.push(s);
        }
    }

    return 0;
}