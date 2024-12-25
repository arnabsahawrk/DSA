// https://leetcode.com/problems/design-browser-history/description/
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
    class Node
    {
    public:
        string data;
        Node *next;
        Node *prev;

        Node(string data)
        {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node *current = nullptr;

    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    string back(int steps)
    {
        for (int i = 1; i <= steps; i++)
        {
            if (current->prev != nullptr)
            {
                current = current->prev;
            }
        }
        return current->data;
    }

    string forward(int steps)
    {
        for (int i = 1; i <= steps; i++)
        {
            if (current->next != nullptr)
            {
                current = current->next;
            }
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */