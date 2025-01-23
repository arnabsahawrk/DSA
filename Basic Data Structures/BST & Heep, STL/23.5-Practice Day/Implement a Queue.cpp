// https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908
#include <bits/stdc++.h>
class Queue
{
    class Node
    {
    public:
        int data;
        Node *next;

        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };
    Node *head, *tail;
    int sz;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        sz++;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;

        int val = head->data;

        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;
        return val;
        sz--;
    }

    int front()
    {
        if (isEmpty())
            return -1;

        return head->data;
    }
};