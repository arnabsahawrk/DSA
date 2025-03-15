#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int i, vector<int> arr, int target) // O(2^n)
{
    if (target == 0)
        return true;
    else if (i < 0)
        return false;

    if (arr[i] <= target)
        return subset_sum(i - 1, arr, target - arr[i]) || subset_sum(i - 1, arr, target);
    else
        return subset_sum(i - 1, arr, target);
}

int main()
{
    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int sum;
    cin >> sum;

    if (subset_sum(n - 1, val, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}