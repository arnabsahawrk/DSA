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

int sizeOfLL = 0;

void display(Node *head, Node *tail)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
    while (tail != nullptr)
    {
        cout << tail->value << " ";
        tail = tail->prev;
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
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    sizeOfLL++;
}

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    sizeOfLL++;
}

void insert_at_position(Node *node, int value, int index)
{
    Node *newNode = new Node(value);

    while (node != nullptr && --index)
    {
        node = node->next;
    }
    newNode->prev = node;
    newNode->next = node->next;
    node->next->prev = newNode;
    node->next = newNode;

    sizeOfLL++;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int q;
    cin >> q;

    while (q--)
    {
        int v, x;
        cin >> v >> x;

        if (v < 0 || v > sizeOfLL)
        {
            cout << "Invalid" << endl;
            continue;
        }
        else if (v == 0)
        {
            insert_at_head(head, tail, x);
        }
        else if (v == sizeOfLL)
        {
            insert_at_tail(head, tail, x);
        }
        else
        {
            insert_at_position(head, x, v);
        }

        display(head, tail);
    }

    return 0;
}