#include <bits/stdc++.h>
using namespace std;

string sameOrNot(stack<int> st, queue<int> q)
{
    while (!st.empty() && !q.empty())
    {
        if (st.top() != q.front())
            return "NO";

        st.pop();
        q.pop();
    }

    if (st.empty() && q.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    int n, m;
    cin >> n >> m;

    stack<int> st;
    queue<int> q;

    while (n--)
    {
        int x;
        cin >> x;

        st.push(x);
    }

    while (m--)
    {
        int x;
        cin >> x;

        q.push(x);
    }

    cout << sameOrNot(st, q);

    return 0;
}