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

void reverse_linked_list(Node *&head, Node *&tail, Node *temp)
{
    if (temp->next == nullptr)
    {
        head = temp;
        return;
    }

    reverse_linked_list(head, tail, temp->next);
    temp->next->next = temp;
    temp->next = nullptr;
    tail = temp;
}

void display(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    reverse_linked_list(head, tail, head);
    display(head);

    return 0;
}