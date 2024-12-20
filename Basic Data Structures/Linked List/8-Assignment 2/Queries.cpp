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

void display(Node *node)
{
    while (node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
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

void insert_at_head(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
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
    tail = tail->next;
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

void delete_at_any_pos(Node *&head, Node *&tail, int index)
{
    if (head == nullptr || index < 0)
        return;

    if (index == 0)
    {
        delete_at_head(head, tail);
        return;
    }

    Node *temp = head;

    for (int i = 0; i < index - 1; i++)
    {
        if (temp == nullptr || temp->next == nullptr)
            return;
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    if (deleteNode == nullptr)
        return;

    if (deleteNode == tail)
    {
        tail = temp;
    }

    temp->next = deleteNode->next;
    delete deleteNode;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int t;
    cin >> t;

    while (t--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            int size = size_of_linked_list(head);
            if (v >= 0 && v < size)
            {
                delete_at_any_pos(head, tail, v);
            }
        }

        display(head);
    }

    return 0;
}
