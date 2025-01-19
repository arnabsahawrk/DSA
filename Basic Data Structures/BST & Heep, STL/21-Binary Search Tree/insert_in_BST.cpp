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

void insert_in_BST(Node *&root, int val)
{
    if (root == nullptr)
        root = new Node(val);
    else if (root->value > val)
    {
        if (root->left == nullptr)
            root->left = new Node(val);
        else
            insert_in_BST(root->left, val);
    }
    else
    {
        if (root->right == nullptr)
            root->right = new Node(val);
        else
            insert_in_BST(root->right, val);
    }
}

void level_order_traversal(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

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

    int value;
    while (cin >> value)
    {
        insert_in_BST(root, value);
    }

    level_order_traversal(root);

    return 0;
}