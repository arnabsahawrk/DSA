#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v; // O(1)

    int n;
    cin >> n;

    vector<int> v2(n);    // O(n)
    vector<int> v3(n, 0); // O(n)
    vector<int> v4(v3);   // O(n)

    int array[5] = {1, 2, 3, 4, 5};
    vector<int> v5(array, array + 5); // O(n)
    vector<int> v6 = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        cout << v6[i] << " ";

    return 0;
}