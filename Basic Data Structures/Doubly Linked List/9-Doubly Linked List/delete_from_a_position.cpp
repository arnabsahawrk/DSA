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

int size_of_DLL(Node *node)
{
    int count = 0;

    while (node != nullptr)
    {
        count++;
        node = node->next;
    }

    return count;
}

void print_forward(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void print_backward(Node *node)
{
    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->prev;
    }
    cout << endl;
}

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
    newNode->prev = tail;
    tail = newNode;
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
        head->prev = nullptr;
    }

    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail)
{
    if (tail == nullptr)
        return;

    Node *deleteNode = tail;

    if (tail == head)
    {
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete deleteNode;
}

void delete_from_a_position(Node *&node, int position)
{
    Node *temp = node;

    while (--position)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deleteNode;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(head, tail, value);
    }

    print_forward(head);
    print_backward(tail);

    int t;
    cin >> t;
    while (t--)
    {
        int index;
        cin >> index;

        int size = size_of_DLL(head);

        if (index < 1)
        {
            delete_at_head(head, tail);
        }
        else if (index >= size)
        {
            delete_at_tail(head, tail);
        }
        else
        {
            delete_from_a_position(head, index);
        }

        print_forward(head);
        print_backward(tail);
    }

    return 0;
}