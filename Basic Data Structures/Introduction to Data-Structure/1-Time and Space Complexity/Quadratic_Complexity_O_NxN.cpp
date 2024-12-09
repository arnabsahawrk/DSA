#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 1; i <= n; i++) // O(N)
    {
        for (int j = 1; j <= n; j++) // O(N)
        {
            cout << i << " ";
        }
    } // O(N * N) -> O(N^2)

    cout << endl; // O(1)

    for (int i = 1; i <= n; i++) // O(N)
    {
        for (int j = 1; j <= n; j++) // O(N)
        {
            for (int k = 1; k <= n; k++) // O(N)
            {

                cout << i << " ";
            }
        }
    } // O(N * N * N) -> O(N^3)

    return 0; // O(1)
}