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
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node *node)
{
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(head, tail, value);
    }

    Node *node = head;

    while (node != nullptr && node->next != nullptr)
    {
        Node *tempNode = node->next;

        while (tempNode != nullptr)
        {
            if (node->value > tempNode->value)
            {
                swap(node->value, tempNode->value);
            }
            tempNode = tempNode->next;
        }

        node = node->next;
    }

    display(head);

    return 0;
}