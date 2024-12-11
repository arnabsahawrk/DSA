#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) // O(N)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end()); // O(NlogN)

    int q;
    cin >> q;

    while (q--) // O(Q)
    {
        int x, l = 0, r = n - 1;
        cin >> x;
        bool found = false;

        while (l <= r) // O(QlogN)
        {
            int mid = l + (r - l) / 2;

            if (v[mid] < x)
            {
                l = mid + 1;
            }
            else if (v[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                found = true;
                break;
            }
        }

        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

// Time Complexity: O(NlogN)