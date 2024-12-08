#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 1; i <= n; i++) // O(N)
    {
        for (int j = 1; j <= n; j *= 2) // O(logN)
        {
            cout << i << " ";
        }
    } // O(N * logN) -> O(NlogN)

    return 0; // O(1)
}