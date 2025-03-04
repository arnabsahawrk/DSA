// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/D
#include <bits/stdc++.h>
using namespace std;

void print_digits(int n)
{
    if (n == 0)
        return;

    print_digits(n / 10);
    cout << n % 10 << " ";
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int digit;
        cin >> digit;

        if (digit > 9)
            print_digits(digit);
        else
            cout << digit;

        cout << endl;
    }

    return 0;
}