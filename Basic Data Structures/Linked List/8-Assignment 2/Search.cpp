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

int search(SinglyLinkedListNode *node, int x)
{
    int foundIndex = 0;

    while (node)
    {
        if (node->value == x)
            return foundIndex;

        foundIndex++;
        node = node->next;
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        SinglyLinkedListNode *head = nullptr, *tail = nullptr;

        int value;
        while (cin >> value && value != -1)
            insert_at_tail(head, tail, value);

        cin >> value;

        cout << search(head, value) << endl;
    }

    return 0;
}