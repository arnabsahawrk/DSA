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

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void isSizeEqual(Node *firstLLHead, Node *secondLLHead)
{
    while (firstLLHead && secondLLHead)
    {
        firstLLHead = firstLLHead->next;
        secondLLHead = secondLLHead->next;
    }

    if (firstLLHead || secondLLHead)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    Node *firstLLHead = nullptr, *firstLLTail = nullptr;
    Node *secondLLHead = nullptr, *secondLLTail = nullptr;

    int value;
    while (cin >> value && value != -1)
        insert_at_tail(firstLLHead, firstLLTail, value);

    while (cin >> value && value != -1)
        insert_at_tail(secondLLHead, secondLLTail, value);

    isSizeEqual(firstLLHead, secondLLHead);

    return 0;
}