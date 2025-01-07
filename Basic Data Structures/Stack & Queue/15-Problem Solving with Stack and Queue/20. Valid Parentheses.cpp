// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> chr;

        for (char c : s)
        {
            if (c == ']')
            {
                if (chr.empty() || chr.top() != '[')
                {
                    return false;
                }
                else
                {
                    chr.pop();
                }
            }
            else if (c == '}')
            {
                if (chr.empty() || chr.top() != '{')
                {
                    return false;
                }
                else
                {
                    chr.pop();
                }
            }
            else if (c == ')')
            {
                if (chr.empty() || chr.top() != '(')
                {
                    return false;
                }
                else
                {
                    chr.pop();
                }
            }
            else
            {
                chr.push(c);
            }
        }

        if (chr.empty())
            return true;
        else
            return false;
    }
};