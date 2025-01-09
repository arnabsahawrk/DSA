/*
You are given a string representing colors, where each letter corresponds to the first letter of a color.
For example, "RGBY" stands for Red, Green, Blue, and Yellow. As we learned in kindergarten,
certain colors can be combined to create new "special colors." Here are the mixing rules for simplicity:

1.Red (R) + Blue (B) = Purple
2.Yellow (Y) + Blue (B) = Green
3.Red (R) + Yellow (Y) = Orange
4. Green(G) + Red(R) = Brown


From the given string, determine if it is possible to make atleast one Brown color by mixing adjacent colors.
You can pick out any special color from the process.


Example:

1.
BYBRRR
Yes

2.
RRYBBY
No
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<int> st;

    for (char c : str)
    {
        if (st.empty())
            st.push(c);
        else
        {
            if ((st.top() == 'G' && c == 'R') || (st.top() == 'R' && c == 'G'))
            {
                cout << "Yes";
                return 0;
            }
            else if ((st.top() == 'B' && c == 'R') || (st.top() == 'R' && c == 'B'))
                st.pop();
            else if ((st.top() == 'Y' && c == 'B') || (st.top() == 'B' && c == 'Y'))
            {
                st.push('G');
            }
            else if ((st.top() == 'R' && c == 'Y') || (st.top() == 'Y' && c == 'R'))
                st.pop();
            else
                st.push(c);
        }
    }

    cout << "No";

    return 0;
}