#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({10, 2});
    pq.push({3, 6});
    pq.push({5, 1});

    cout << pq.top().first << " " << pq.top().second << endl; // it prioritize the first value of the pair
    return 0;
}