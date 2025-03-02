#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n) // time complexity: O(N)
{
    if (n < 2)
        return n;

    long long prev2 = 0, prev1 = 1, curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev2 + prev1;
        prev2 = prev1, prev1 = curr;
    }

    return curr;
} // space complexity: O(1)

int main()
{

    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}