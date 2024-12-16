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

void isSorted(Node *node)
{
    while (node->next != nullptr)
    {
        if (node->value > node->next->value)
        {
            cout << "NO" << endl;
            return;
        }
        node = node->next;
    }

    cout << "YES" << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    isSorted(head);

    return 0;
}