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

void display(Node *node)
{
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int size_of_linked_list(Node *node)
{
    int count = 0;

    while (node)
    {
        count++;
        node = node->next;
    }

    return count;
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
    tail = tail->next;
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

void insert_at_any_pos(Node *&head, Node *&tail, int data, int pos)
{
    if (pos < 0 || pos > size_of_linked_list(head))
    {
        cout << "Invalid" << endl;
    }
    else if (pos == 0)
    {
        insert_at_head(head, tail, data);
        display(head);
    }
    else if (pos == size_of_linked_list(head))
    {
        insert_at_tail(head, tail, data);
        display(head);
    }
    else
    {
        Node *newNode = new Node(data);

        Node *current = head;
        while (current && --pos)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        display(head);
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
    {
        if (value == -1)
            break;

        insert_at_tail(head, tail, value);
    }

    int pos;
    while (cin >> pos >> value)
        insert_at_any_pos(head, tail, value, pos);

    return 0;
}