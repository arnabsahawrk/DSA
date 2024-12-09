#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 1; i <= n; i *= 2) // O(log2N) ignore constant so, O(logN)
    {
        cout << i << " ";
    }

    cout << endl; // O(1)

    for (int i = n; i >= 1; i /= 3) // O(log3N) ignore constant so, O(logN)
    {
        cout << i << " ";
    }

    int k = 2;                   // O(1)
    for (int j = 1; j <= n; j++) // O(logkN) ignore constant so, O(logN)
    {
        cout << j << " ";
        j = j * k;
    }

    return 0; // O(1)
}

/*
n = 1000

1    2    4    8    16    32    64    128    256    512
2^0  2^1  2^2  2^3  2^4   2^5   ....................2^k

log2^2^k = log2^1000
klog2^2 = log2^1000
k = log2^1000     [loga^a = 1]
k = log2^N   [1000 = N]

ignore the constant so, the operation will O(logN)

If our code iteration will increment and decrement by * or / then the complexity will O(log N)
*/