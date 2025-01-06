#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

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