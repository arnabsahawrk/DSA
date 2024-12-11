// https://codeforces.com/group/MWSDmqGsZm/contest/223206/problem/L

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long serejaSum = 0, dimaSum = 0;

    int move = 1;

    while (!v.empty())
    {
        if (move)
        {
            if (v.front() > v.back())
            {
                serejaSum += v.front();
                v.erase(v.begin());
                move = 0;
            }
            else
            {
                serejaSum += v.back();
                v.pop_back();
                move = 0;
            }
        }
        else
        {
            if (v.front() > v.back())
            {
                dimaSum += v.front();
                v.erase(v.begin());
                move = 1;
            }
            else
            {
                dimaSum += v.back();
                v.pop_back();
                move = 1;
            }
        }
    }

    cout << serejaSum << " " << dimaSum;

    return 0;
}