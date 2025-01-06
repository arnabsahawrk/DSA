// https://leetcode.com/problems/implement-queue-using-stacks/

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> st, st2;

public:
    MyQueue() {}

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        int val;
        if (!st2.empty())
        {
            val = st2.top();
            st2.pop();
        }
        else
        {
            while (!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }

            val = st2.top();
            st2.pop();
        }

        return val;
    }

    int peek()
    {
        int val;
        if (!st2.empty())
        {
            val = st2.top();
        }
        else
        {
            while (!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }

            val = st2.top();
        }

        return val;
    }

    bool empty()
    {
        return st.empty() && st2.empty();
    }
};