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

int size_of_DLL(Node *node)
{
    int count = 0;

    while (node != nullptr)
    {
        count++;
        node = node->next;
    }

    return count;
}

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

void insert_at_a_postion(Node *&node, int value, int position)
{
    Node *newNode = new Node(value);
    Node *temp = node;

    while (--position)
    {
        temp = temp->next;
    }

    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value, index;
    while (cin >> value >> index)
    {
        int size = size_of_DLL(head);

        if (index < 1)
        {
            insert_at_head(head, tail, value);
        }
        else if (index >= size)
        {
            insert_at_tail(head, tail, value);
        }
        else
        {
            insert_at_a_postion(head, value, index);
        }
    }

    print_forward(head);
    print_backward(tail);

    return 0;
}