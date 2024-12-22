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

void insert_at_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value)
    {
        insert_at_head(head, tail, value);
    }

    print_forward(head);

    return 0;
}