#include <bits/stdc++.h>
using namespace std;

void recursion(int n)
{
    if (n > 5)
    {
        cout << endl;
        return;
    }

    cout << n << " "; // 1 to 5 printing
    recursion(n + 1);
    cout << n << " "; // 5 to 1 reverse printing
}

void recursionSum(int n, int sum)
{
    if (n > 5)
    {
        cout << endl
             << "Sum of 1 to 5 is: " << sum << endl;
        return;
    }
    recursionSum(n + 1, sum + n);
}

int main()
{
    recursion(1);
    recursionSum(1, 0);
    return 0;
}