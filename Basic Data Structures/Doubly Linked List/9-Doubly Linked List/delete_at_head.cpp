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

void delete_at_head(Node *&head, Node *&tail)
{
    if (head == nullptr)
        return;

    Node *deleteNode = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {

        head = head->next;
        head->prev = nullptr;
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

    delete_at_head(head, tail);
    delete_at_head(head, tail);

    print_forward(head);

    return 0;
}