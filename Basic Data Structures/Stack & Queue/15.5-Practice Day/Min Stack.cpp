// https://www.naukri.com/code360/problems/min-stack_3843991
#include <bits/stdc++.h>
using namespace std;

class minStack
{
    class Node
    {
    public:
        pair<int, int> data;
        Node *next;

        Node(pair<int, int> data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *head;

public:
    minStack()
    {
        head = nullptr;
    }

    void push(int num)
    {
        if (head == nullptr)
        {
            Node *newNode = new Node({num, num});
            head = newNode;
        }
        else
        {
            Node *newNode = new Node({num, min(num, head->data.second)});
            newNode->next = head;
            head = newNode;
        }
    }

    int pop()
    {
        if (head == nullptr)
            return -1;

        int val = head->data.first;

        Node *deleteNode = head;
        head = head->next;

        delete deleteNode;
        return val;
    }

    int top()
    {
        if (head == nullptr)
            return -1;

        return head->data.first;
    }

    int getMin()
    {
        if (head == nullptr)
            return -1;

        return head->data.second;
    }
};