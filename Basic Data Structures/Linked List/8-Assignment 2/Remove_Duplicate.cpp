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

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void removeDuplicate(Node *&head, Node *&tail)
{
    if (head == nullptr)
        return;

    for (Node *i = head; i != nullptr; i = i->next)
    {
        Node *prev = i;
        for (Node *j = i->next; j != nullptr;)
        {
            if (i->value == j->value)
            {
                Node *deleteNode = j;
                prev->next = j->next;
                j = j->next;
                if (deleteNode == tail)
                    tail = prev;

                delete deleteNode;
            }
            else
            {
                prev = j;
                j = j->next;
            }
        }
    }
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value && value != -1)
        insert_at_tail(head, tail, value);

    removeDuplicate(head, tail);
    display(head);

    return 0;
}