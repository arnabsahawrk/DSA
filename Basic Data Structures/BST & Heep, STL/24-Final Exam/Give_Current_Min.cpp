#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, value;
    cin >> t;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (t--)
    {
        cin >> value;
        pq.push(value);
    }

    cin >> t;

    while (t--)
    {
        cin >> value;

        if (value == 0)
        {
            cin >> value;
            pq.push(value);
            cout << pq.top() << endl;
        }
        else if (value == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
        else
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
            {
                pq.pop();

                if (pq.empty())
                    cout << "Empty" << endl;
                else
                    cout << pq.top() << endl;
            }
        }
    }

    return 0;
}