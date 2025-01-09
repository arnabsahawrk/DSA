// https://www.naukri.com/code360/problems/reverse-first-k-elements-of-queue_982771
#include <bits/stdc++.h>
using namespace std;
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> st;
    queue<int> ans;

    while (k--)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }

    return ans;
}
