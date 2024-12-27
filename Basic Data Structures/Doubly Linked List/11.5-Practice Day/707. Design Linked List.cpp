// https://leetcode.com/problems/design-linked-list/

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->next = nullptr;
    }
};
class MyLinkedList
{
public:
    int sizeLL = 0;
    Node *head, *tail;
    MyLinkedList()
    {
        head = nullptr, tail = nullptr;
    }

    int get(int index)
    {
        if (index >= sizeLL)
            return -1;

        Node *temp = head;
        while (--index)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        sizeLL++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

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

    void addAtIndex(int index, int val)
    {
        if (index > sizeLL)
            return;
        else if (index == sizeLL)
            addAtTail(val);
        else if (index == 0)
            addAtHead(val);
        else
        {
            Node *newNode = new Node(val);
            Node *temp = head;
            while (--index)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;

            sizeLL++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < sizeLL)
        {
            if (index == 0)
            {
                Node *deleteNode = head;
                head = head->next;
                head->prev = nullptr;

                delete deleteNode;
            }
            else if (index == sizeLL - 1)
            {
                Node *deleteNode = tail;
                tail = tail->prev;
                tail->next = nullptr;

                delete deleteNode;
            }
            else
            {
                Node *temp = head;
                while (--index)
                {
                    temp = temp->next;
                }
                Node *deleteNode = temp->next;
                temp->next->next->prev = temp;
                temp->next = temp->next->next;

                delete deleteNode;
            }

            sizeLL--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */