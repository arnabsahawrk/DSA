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

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int max_in_singly_linked_list(Node *node)
{
    if (node == nullptr)
        return -1;

    int maxValue = node->value;
    while (node->next != nullptr)
    {
        maxValue = max(maxValue, node->next->value);
        node = node->next;
    }

    return maxValue;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    cout << max_in_singly_linked_list(head) << endl;

    return 0;
}