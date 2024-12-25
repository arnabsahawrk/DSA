#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void print_forward(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void print_backward(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = new Node(50);

    head->next = a;

    a->prev = head;
    a->next = b;

    b->prev = a;
    b->next = c;

    c->prev = b;
    c->next = tail;

    tail->prev = c;

    print_forward(head);
    print_backward(tail);

    return 0;
}