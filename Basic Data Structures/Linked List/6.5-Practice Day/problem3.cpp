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

void print_the_middle_element(Node *node)
{
    int size = size_of_linked_list(node);
    if (size & 1)
    {
        size /= 2;
        while (node && size--)
        {
            node = node->next;
        }
        cout << node->value << endl;
    }
    else
    {
        size /= 2;
        while (node && --size)
        {
            node = node->next;
        }
        cout << node->value << " " << node->next->value << endl;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    print_the_middle_element(head);

    return 0;
}