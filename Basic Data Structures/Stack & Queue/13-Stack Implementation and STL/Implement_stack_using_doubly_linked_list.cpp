#include <bits/stdc++.h>
using namespace std;

class myStack
{
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

    int sizeLL = 0;

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

        sizeLL++;
    }

    void delete_at_tail(Node *&head, Node *&tail)
    {
        if (tail == nullptr)
            return;

        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete deleteNode;
        sizeLL--;
    }

    int get_tail_value(Node *node)
    {
        if (node == nullptr)
            return -1;

        return node->value;
    }

    bool is_empty(Node *node)
    {
        if (node == nullptr)
            return true;
        else
            return false;
    }

    Node *head = nullptr, *tail = nullptr;

public:
    void push(int value)
    {
        insert_at_tail(head, tail, value);
    }

    void pop()
    {
        delete_at_tail(head, tail);
    }

    int top()
    {
        return get_tail_value(tail);
    }

    int size()
    {
        return sizeLL;
    }

    bool empty()
    {
        return is_empty(tail);
    }
};

int main()
{
    myStack st;

    int value;
    while (cin >> value)
    {
        st.push(value);
    }

    cout << "Stack Size: " << st.size() << endl
         << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl
         << endl
         << "Stack Size: " << st.size() << endl;

    return 0;
}