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

int size_of_LL(SinglyLinkedListNode *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }

    return count;
}

bool same_to_same(SinglyLinkedListNode *firstHeadNode, SinglyLinkedListNode *secondHeadNode)
{
    int firstSize = size_of_LL(firstHeadNode);
    int secondSize = size_of_LL(secondHeadNode);

    if (firstSize != secondSize)
        return false;

    while (firstHeadNode && secondHeadNode)
    {
        if (firstHeadNode->value != secondHeadNode->value)
            return false;

        firstHeadNode = firstHeadNode->next;
        secondHeadNode = secondHeadNode->next;
    }

    return true;
}

int main()
{
    SinglyLinkedListNode *firstHead = nullptr, *firstTail = nullptr;
    SinglyLinkedListNode *secondHead = nullptr, *secondTail = nullptr;

    int value;
    while (cin >> value && value != -1)
        insert_at_tail(firstHead, firstTail, value);

    while (cin >> value && value != -1)
        insert_at_tail(secondHead, secondTail, value);

    if (same_to_same(firstHead, secondHead))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}