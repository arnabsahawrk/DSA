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

void ascending_sort(Node *node)
{
    while (node->next)
    {
        Node *tempNode = node->next;
        while (tempNode)
        {
            if (tempNode && node->value > tempNode->value)
            {
                swap(node->value, tempNode->value);
            }
            tempNode = tempNode->next;
        }
        node = node->next;
    }
}

void descending_sort(Node *node)
{
    for (Node *i = node; i->next != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->value < j->value)
                swap(i->value, j->value);
        }
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    display(head);

    ascending_sort(head);
    display(head);

    descending_sort(head);
    display(head);

    return 0;
}