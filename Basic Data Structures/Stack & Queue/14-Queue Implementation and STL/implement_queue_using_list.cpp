#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    list<int> l;

public:
    void enqueue(int val)
    {
        l.push_back(val);
    }

    void dequeue()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }

    int back()
    {
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
    }
};

int main()
{
    myQueue q;

    int value;
    while (cin >> value)
    {
        q.enqueue(value);
    }

    while (!q.empty())
    {
        cout << "Size: " << q.size() << endl;
        cout << q.front() << " " << q.back() << endl;
        cout << endl;

        q.dequeue();
    }

    cout << "Size: " << q.size() << endl;

    return 0;
}