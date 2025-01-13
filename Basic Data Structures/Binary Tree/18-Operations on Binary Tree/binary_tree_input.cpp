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
            q.push(parent->left);

        if (parent->right)
            q.push(parent->right);
    }
}

void level_order(Node *node)
{
    if (node == nullptr)
        return;

    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << front->value << " ";

        if (front->left)
            q.push(front->left);

        if (front->right)
            q.push(front->right);
    }
}

int main()
{

    Node *root = nullptr;

    input_tree(root);
    level_order(root);

    return 0;
}