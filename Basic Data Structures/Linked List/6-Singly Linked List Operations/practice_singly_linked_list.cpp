// https: // docs.google.com/document/d/1P9adF6lPRgQcQFZH0Bq4e8tPxa5pdiBlxuJlS7p8jXg/edit?tab=t.0#heading=h.mv28ybtyyja3

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

int size_of_the_list(Node *node)
{
    int count = 0;

    while (node)
    {
        count++;
        node = node->next;
    }

    return count;
}

void insert_at_head(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

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

void insert_at_pos(Node *&head, Node *&tail, int pos, int data)
{
    if (pos <= 1)
    {
        insert_at_head(head, tail, data);
        return;
    }
    else if (pos > size_of_the_list(head))
    {
        insert_at_tail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    Node *current = head;
    while (current->next != nullptr && --pos)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
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

void reverse_display(Node *node)
{
    if (node == nullptr)
        return;

    reverse_display(node->next);
    cout << node->value << " ";
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    insert_at_head(head, tail, 100);
    insert_at_pos(head, tail, 3, 400);

    cout << size_of_the_list(head) << endl;
    display(head);
    reverse_display(head);

    return 0;
}