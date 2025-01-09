// https://leetcode.com/problems/backspace-string-compare/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st, st2;

        for (char c : s)
        {
            if (c != '#')
                st.push(c);
            else if (!st.empty())
                st.pop();
        }

        for (char c : t)
        {
            if (c != '#')
                st2.push(c);
            else if (!st2.empty())
                st2.pop();
        }

        while (!st.empty() && !st2.empty())
        {
            if (st.top() != st2.top())
                return false;

            st.pop();
            st2.pop();
        }

        if (st.empty() && st2.empty())
            return true;
        else
            return false;
    }
};