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

int sizeLL = 0;

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    sizeLL++;
}
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    sizeLL++;
}
void insert_at_index(Node *head, int val, int idx)
{
    Node *newNode = new Node(val);

    Node *temp = head;
    while (idx--)
    {
        temp = temp->next;
    }
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;

    sizeLL++;
}

void display(Node *head, Node *tail)
{
    Node *temp = head;
    cout << "L -> ";
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = tail;
    cout << "R -> ";
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int query;
    cin >> query;

    while (query--)
    {
        int v, x;
        cin >> v >> x;

        if (v == 0)
        {
            insert_at_head(head, tail, x);
            display(head, tail);
        }
        else if (v == sizeLL)
        {
            insert_at_tail(head, tail, x);
            display(head, tail);
        }
        else if (v > 0 && v < sizeLL)
        {
            insert_at_index(head, x, v);
            display(head, tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}