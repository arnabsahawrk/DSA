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

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

string isSame(Node *fHead, Node *sHead)
{
    while (fHead != nullptr && sHead != nullptr)
    {
        if (fHead->value != sHead->value)
        {
            return "NO";
        }
        fHead = fHead->next;
        sHead = sHead->next;
    }

    if (fHead != nullptr || sHead != nullptr)
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}

int main()
{
    Node *firstHead = nullptr, *firstTail = nullptr, *secondHead = nullptr, *secondTail = nullptr;

    int value;
    while (cin >> value && value != -1)
    {
        insert_at_tail(firstHead, firstTail, value);
    }

    while (cin >> value && value != -1)
    {
        insert_at_tail(secondHead, secondTail, value);
    }

    cout << isSame(firstHead, secondHead) << endl;

    return 0;
}