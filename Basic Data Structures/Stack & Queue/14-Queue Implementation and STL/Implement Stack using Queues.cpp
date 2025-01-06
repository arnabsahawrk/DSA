// https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        int s = q.size();

        q.push(x);

        while (s--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};