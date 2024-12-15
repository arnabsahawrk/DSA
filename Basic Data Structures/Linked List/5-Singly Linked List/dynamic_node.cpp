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
        this->next = nullptr;
    }
};

int main()
{
    Node *head = new Node(999);
    Node *a = new Node(111);
    Node *b = new Node(222);

    head->next = a;
    a->next = b;

    cout << head->value << endl;
    cout << head->next->value << endl;
    cout << head->next->next->value << endl;

    return 0;
}