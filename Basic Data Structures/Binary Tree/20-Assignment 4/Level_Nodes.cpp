#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void input_tree(Node *&root)
{
    int value;
    cin >> value;

    if (value != -1)
        root = new Node(value);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int left, right;
        cin >> left >> right;

        Node *leftChild = nullptr, *rightChild = nullptr;
        if (left != -1)
            leftChild = new Node(left);
        if (right != -1)
            rightChild = new Node(right);

        parent->left = leftChild;
        parent->right = rightChild;

        if (parent->left)
            q.push(leftChild);
        if (parent->right)
            q.push(rightChild);
    }
}

void level_nodes(Node *root, int x)
{
    queue<Node *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();

        if (level == x)
        {
            for (int i = 0; i < sz; i++)
            {
                cout << q.front()->value << " ";
                q.pop();
            }

            cout << endl;
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }

        level++;
    }

    cout << "Invalid" << endl;
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    int x;
    cin >> x;

    level_nodes(root, x);

    return 0;
}