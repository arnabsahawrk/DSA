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

void delete_at_head(Node *&head, Node *&tail)
{
    if (head == nullptr)
        return;

    Node *deleteNode = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
    }

    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    if (tail == nullptr)
        return;

    if (head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void delete_at_any_pos(Node *&head, Node *&tail, int pos)
{
    if (pos < 2)
    {
        delete_at_head(head, tail);
        return;
    }
    else if (pos >= size_of_linked_list(head))
    {
        delete_at_tail(head, tail);
        return;
    }

    Node *temp = head;
    while (temp && --pos)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;

    delete deleteNode;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int value;
    while (cin >> value)
        insert_at_tail(head, tail, value);

    delete_at_any_pos(head, tail, 4);

    display(head);

    return 0;
}