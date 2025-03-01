// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (st.empty())
                st.push(c);
            else
            {
                if (st.top() == c)
                    st.pop();
                else
                    st.push(c);
            }
        }

        s = "";
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());

        return s;
    }
};