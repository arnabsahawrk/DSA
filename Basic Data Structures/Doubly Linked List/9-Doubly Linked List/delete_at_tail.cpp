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

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    if (tail == nullptr)
        return;

    Node *deleteNode = tail;

    if (tail == head)
    {
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete deleteNode;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value)
    {
        insert_at_tail(head, tail, value);
    }

    delete_at_tail(head, tail);
    delete_at_tail(head, tail);

    print_forward(head);

    return 0;
}