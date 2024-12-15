#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

int main()
{

    Node a(100), b(200), c(300);

    a.next = &b;
    b.next = &c;

    cout << a.value << " " << b.value << " " << c.value << endl;

    cout << a.value << endl;
    cout << (*a.next).value << endl;
    cout << a.next->next->value << endl;

    return 0;
}