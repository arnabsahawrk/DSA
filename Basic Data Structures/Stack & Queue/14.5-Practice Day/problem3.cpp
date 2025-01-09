#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st, st2;
    
    int t;
    cin >> t;

    while (t--)
    {
        int value;
        cin >> value;

        st.push(value);
    }

    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }

    return 0;
}