#include <bits/stdc++.h>
using namespace std;

string isSame(stack<int> st, queue<int> q)
{
    while (!st.empty() && !q.empty())
    {
        if (st.top() != q.front())
        {
            return "NO";
        }

        st.pop();
        q.pop();
    }

    if (!st.empty() || !q.empty())
        return "NO";
    else
        return "YES";
}

int main()
{
    stack<int> n;
    queue<int> m;
    int t;

    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        n.push(x);
    }

    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        m.push(x);
    }

    cout << isSame(n, m);

    return 0;
}