#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int count = 0;

    for (auto numb : v) // O(N)
    {
        int value = numb + 1;

        auto isFound = find(v.begin(), v.end(), value); // O(N)

        int index = isFound - v.begin();

        if (index < n)
            count++;
    } // O(N * N)

    cout << count;
    return 0;
}

// O(N * N)