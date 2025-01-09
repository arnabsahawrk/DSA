// https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack
{
    Node *head;
    int sz;

public:
    Stack()
    {
        head = NULL;
        sz = 0;
    }

    int getSize()
    {
        return sz;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        sz++;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;
        sz--;
    }

    int getTop()
    {
        if (isEmpty())
            return -1;

        return head->data;
    }
};