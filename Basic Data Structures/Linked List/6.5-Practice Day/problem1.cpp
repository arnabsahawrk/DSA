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

void size_of_linked_list(Node *node)
{
    int count = 0;

    while (node)
    {
        count++;
        node = node->next;
    }

    cout << count << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    size_of_linked_list(head);

    return 0;
}