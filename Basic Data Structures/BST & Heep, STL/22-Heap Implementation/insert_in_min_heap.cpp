#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int value;
    cin >> value;
    v.push_back(value);

    int currentIndex = v.size() - 1;
    while (currentIndex != 0)
    {
        int parentIndex = (currentIndex - 1) / 2;

        if (v[parentIndex] > v[currentIndex])
            swap(v[parentIndex], v[currentIndex]);
        else
            break;

        currentIndex = parentIndex;
    }

    for (auto x : v)
        cout << x << " ";

    return 0;
}