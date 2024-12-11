// https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/Z

// Concept: Binary Search, Time Complexity: O(logN)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++) // O(N)
        cin >> v[i];

    sort(v.begin(), v.end()); // O(NlogN)

    while (q--) // O(Q)
    {
        int x, start = 0, end = n - 1;
        cin >> x;

        bool found = false;

        while (start <= end) // O(logN)
        {
            int mid = start + (end - start) / 2;

            if (v[mid] > x)
                end = mid - 1;
            else if (v[mid] < x)
                start = mid + 1;
            else
            {
                found = true;
                break;
            }
        }

        if (found)
            cout << "found" << endl;
        else
            cout << "not found" << endl;
    } // O(QlogN)

    return 0;
}

// O(NlogN)