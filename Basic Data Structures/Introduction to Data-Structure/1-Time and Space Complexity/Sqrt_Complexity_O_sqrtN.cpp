#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;    // O(1)
    cin >> n; // O(1)

    for (int i = 1; i * i <= n; i++) // O(sqrt(N))
    {
        cout << i << " ";
    }

    return 0; // O(1)
}

/*
i * i <= n
i^2 <= n
i <= √n
*/