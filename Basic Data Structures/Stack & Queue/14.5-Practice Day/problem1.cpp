#include <bits/stdc++.h>
using namespace std;

class myStack
{
    list<int> l;

public:
    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_back();
    }

    int peek()
    {
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
    }
};

string isSame(myStack st, myStack st2)
{
    while (!st.empty() && !st2.empty())
    {
        if (st.peek() != st2.peek())
        {
            return "NO";
        }

        st.pop();
        st2.pop();
    }

    if (!st.empty() || !st2.empty())
        return "NO";
    else
        return "YES";
}

int main()
{
    myStack n, m;
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