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

int main()
{
    Node *head = new Node(100);
    Node *a = new Node(100);
    Node *b = new Node(100);
    Node *c = new Node(100);
    Node *d = new Node(100);
    Node *tail = new Node(100);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = tail;
    tail->next = a;

    Node *slow = head, *fast = head;
    bool cycleDetected = false;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cycleDetected = true;
            break;
        }
    }

    if (cycleDetected)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }

    return 0;
}