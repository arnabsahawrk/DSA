// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/J
#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n)
{
    if (n == 1)
        return n;

    return n * factorial(n - 1);
}

int main()
{
    long long n;
    cin >> n;

    cout << factorial(n);
    return 0;
}