#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority queue use heap mechanism under the hood.
    priority_queue<int> pq; // high to low

    pq.push(3);
    pq.push(10);
    pq.push(4);

    cout << pq.top() << endl;

    pq.pop();
    cout << pq.top() << endl;

    if (pq.empty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;

    priority_queue<int, vector<int>, greater<int>> pq2; // low to high

    pq2.push(3);
    pq2.push(10);
    pq2.push(4);

    cout << pq2.top() << endl;

    pq2.pop();
    cout << pq2.top() << endl;

    if (pq2.empty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
    return 0;
}