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

void insert_at_head(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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
    Node *head = new Node(5);

    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);

    print_linked_list(head);

    return 0;
}