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

void sort_in_descending_order(SinglyLinkedListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    while (head->next != nullptr)
    {
        SinglyLinkedListNode *temp = head->next;

        while (temp)
        {
            if (head->value < temp->value)
                swap(head->value, temp->value);

            temp = temp->next;
        }
        head = head->next;
    }
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

    sort_in_descending_order(head);

    display(head);

    return 0;
}