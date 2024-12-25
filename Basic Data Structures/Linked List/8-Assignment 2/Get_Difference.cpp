#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode
{
public:
    int value;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

void insert_at_tail(SinglyLinkedListNode *&head, SinglyLinkedListNode *&tail, int value)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(value);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int getDifference(SinglyLinkedListNode *node)
{
    int maxValue = node->value, minValue = node->value;

    node = node->next;
    while (node)
    {
        if (maxValue < node->value)
            maxValue = max(maxValue, node->value);
        else if (minValue > node->value)
            minValue = min(minValue, node->value);

        node = node->next;
    }

    return maxValue - minValue;
}

int main()
{
    SinglyLinkedListNode *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value && value != -1)
        insert_at_tail(head, tail, value);

    cout << getDifference(head);

    return 0;
}