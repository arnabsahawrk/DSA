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
}

string isPalindrome(Node *head, Node *tail)
{
    if (head == nullptr || head == tail)
        return "YES";
    for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
    {
        if (i->value != j->value)
            return "NO";
    }

    return "YES";
}

int main()
{
    Node *head = nullptr, *tail = nullptr;

    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(head, tail, value);
    }

    cout << isPalindrome(head, tail);

    return 0;
}