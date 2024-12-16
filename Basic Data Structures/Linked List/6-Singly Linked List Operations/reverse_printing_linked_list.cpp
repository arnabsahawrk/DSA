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

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void reverse_printing_linked_list(Node *node)
{
    if (node == nullptr)
        return;

    reverse_printing_linked_list(node->next);
    cout << node->value << " ";
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    reverse_printing_linked_list(head);

    return 0;
}