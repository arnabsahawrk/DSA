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

void insert_at_tail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void display(Node *node)
{
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
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
    }

    delete deleteNode;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    delete_at_head(head, tail);

    display(head);

    return 0;
}