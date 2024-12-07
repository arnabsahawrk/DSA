#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 1; i <= n; i += 2) // O(n/2) ignore constant so, O(n)
    {
        cout << i << " ";
    }

    cout << endl; // O(1)

    for (int j = 1; j <= n; j++) // O(n)
    {
        cout << j << " ";
    }

    return 0; // O(1)
}

// O(n + n + 4) --> O(2n + 4) --> ignore constant O(n)

// if our code iteration will increment or decrement by + or - the the time complexity will O(n)