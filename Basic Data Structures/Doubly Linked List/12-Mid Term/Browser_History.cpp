#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string address;
    Node *next;
    Node *prev;

    Node(string address)
    {
        this->address = address;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insert_at_tail(Node *&head, Node *&tail, string address)
{
    Node *newNode = new Node(address);

    if (head == nullptr)
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
}

int main()
{
    Node *head = nullptr, *tail = nullptr, *current = head;

    string address;
    while (cin >> address && address != "end")
    {
        insert_at_tail(head, tail, address);
    }

    int query;
    cin >> query;

    while (query--)
    {
        string str;
        cin >> str;

        if (str == "visit")
        {
            cin >> address;

            Node *temp = head;
            bool found = false;

            while (temp != nullptr)
            {
                if (temp->address == address)
                {
                    found = true;
                    break;
                }

                temp = temp->next;
            }

            if (found)
            {
                cout << address << endl;
                current = temp;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (str == "prev")
        {
            if (current->prev != nullptr)
            {
                cout << current->prev->address << endl;
                current = current->prev;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else
        {
            if (current->next != nullptr)
            {
                cout << current->next->address << endl;
                current = current->next;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}