#include <bits/stdc++.h>
using namespace std;

class myStack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v.back();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
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