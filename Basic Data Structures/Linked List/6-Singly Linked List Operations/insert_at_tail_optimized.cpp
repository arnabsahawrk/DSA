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

void insert_at_tail_optimized(Node *&head, Node *&tail, int data)
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

void print_linked_list(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insert_at_tail_optimized(head, tail, 5);
    insert_at_tail_optimized(head, tail, 4);
    insert_at_tail_optimized(head, tail, 3);
    insert_at_tail_optimized(head, tail, 2);
    insert_at_tail_optimized(head, tail, 1);

    print_linked_list(head);

    return 0;
}