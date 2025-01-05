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

    int top()
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

int main()
{
    myStack st;

    int value;
    while (cin >> value)
    {
        st.push(value);
    }

    cout << "Stack Size: " << st.size() << endl
         << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl
         << endl
         << "Stack Size: " << st.size() << endl;

    return 0;
}