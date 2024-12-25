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

void reverseSinglyLinkedList(SinglyLinkedListNode *&head, SinglyLinkedListNode *&tail)
{
    if (head == nullptr || head == tail)
        return;

    SinglyLinkedListNode *prev = nullptr, *temp = head;

    while (temp)
    {
        SinglyLinkedListNode *capture = temp->next;
        temp->next = prev;
        prev = temp;
        temp = capture;
    }

    tail = head;
    head = prev;
}

void display(SinglyLinkedListNode *node)
{
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    SinglyLinkedListNode *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    reverseSinglyLinkedList(head, tail);

    display(head);

    return 0;
}