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

void insert_at_any_pos(Node *&head, int pos, int data)
{
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;

    while (current && --pos)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void print_linked_list(Node *head)
{
    while (head)
    {
        cout << head->value << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = nullptr;

    insert_at_any_pos(head, 1, 1); 
    insert_at_any_pos(head, 1, 2);
    insert_at_any_pos(head, 2, 4);
    insert_at_any_pos(head, 2, 3);
    insert_at_any_pos(head, 4, 5);

    print_linked_list(head);

    return 0;
}