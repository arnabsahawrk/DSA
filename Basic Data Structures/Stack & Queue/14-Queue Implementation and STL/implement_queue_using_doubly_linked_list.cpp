#include <bits/stdc++.h>
using namespace std;

class myQueue
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
    Node *head = nullptr, *tail = nullptr;
    int sizeLL = 0;

    void insert_at_tail(int value)
    {
        Node *newNode = new Node(value);

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

        sizeLL++;
    }

    void delete_at_head()
    {
        if (head == nullptr)
            return;

        Node *deleteNode = head;

        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete deleteNode;

        sizeLL--;
    }

    int get_head_value()
    {
        if (head == nullptr)
            return -1;

        return head->value;
    }

    int get_tail_value()
    {
        if (tail == nullptr)
            return -1;

        return tail->value;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

public:
    void enqueue(int val)
    {
        insert_at_tail(val);
    }

    void dequeue()
    {
        delete_at_head();
    }

    int front()
    {
        return get_head_value();
    }

    int back()
    {
        return get_tail_value();
    }

    int size()
    {
        return sizeLL;
    }

    bool empty()
    {
        return is_empty();
    }
};

int main()
{
    myQueue q;

    int value;
    while (cin >> value)
    {
        q.enqueue(value);
    }

    while (!q.empty())
    {
        cout << "Size: " << q.size() << endl;
        cout << q.front() << " " << q.back() << endl;
        cout << endl;

        q.dequeue();
    }

    cout << "Size: " << q.size() << endl;

    return 0;
}