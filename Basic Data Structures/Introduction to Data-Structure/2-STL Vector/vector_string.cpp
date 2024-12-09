#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> v(n);

    for (int i = 0; i < n; i++)
        getline(cin, v[i]);

    for (auto str : v)
        cout << str << endl;

    return 0;
}