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

    class myStack
    {
        Node *head = nullptr;

    public:
        void push(int val)
        {
            Node *newNode = new Node(val);
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        void pop()
        {
            if (head == nullptr)
                return;

            Node *deleteNode = head;
            head = head->next;

            delete deleteNode;
        }

        int top()
        {
            if (head == nullptr)
                return -1;

            return head->value;
        }

        bool empty()
        {
            return head == nullptr;
        }
    };

    class myQueue
    {
        Node *head = nullptr, *tail = nullptr;

    public:
        void push(int val)
        {
            Node *newNode = new Node(val);
            if (tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop()
        {
            if (head == nullptr)
                return;

            Node *deleteNode = head;
            head = head->next;

            delete deleteNode;
        }

        int front()
        {
            if (head == nullptr)
                return -1;

            return head->value;
        }

        bool empty()
        {
            return head == nullptr;
        }
    };

    string sameOrNot(myStack st, myQueue q)
    {
        while (!st.empty() && !q.empty())
        {
            if (st.top() != q.front())
                return "NO";

            st.pop();
            q.pop();
        }

        if (st.empty() && q.empty())
            return "YES";
        else
            return "NO";
    }

    int main()
    {
        int n, m;
        cin >> n >> m;

        myStack st;
        myQueue q;

        while (n--)
        {
            int x;
            cin >> x;

            st.push(x);
        }

        while (m--)
        {
            int x;
            cin >> x;

            q.push(x);
        }

        cout << sameOrNot(st, q);

        return 0;
    }