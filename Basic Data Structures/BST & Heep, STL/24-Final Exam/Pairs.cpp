#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> left, pair<string, int> right)
{
    return left.first == right.first ? left.second > right.second : left.first < right.first;
};

int main()
{
    int t;
    cin >> t;

    vector<pair<string, int>> v;

    while (t--)
    {
        string S;
        int I;
        cin >> S >> I;
        v.push_back(make_pair(S, I));
    }

    sort(v.begin(), v.end(), compare);

    for (auto value : v)
        cout << value.first << " " << value.second << endl;

    return 0;
}