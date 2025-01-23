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

        int leftValue, rightValue;
        cin >> leftValue >> rightValue;
        Node *leftNode = nullptr, *rightNode = nullptr;

        if (leftValue != -1)
            leftNode = new Node(leftValue);
        if (rightValue != -1)
            rightNode = new Node(rightValue);

        parent->left = leftNode;
        parent->right = rightNode;

        if (parent->left)
            q.push(leftNode);
        if (parent->right)
            q.push(rightNode);
    }
}

bool search_in_BST(Node *root, int val)
{
    if (root == nullptr)
        return false;
    else if (root->value == val)
        return true;
    else if (root->value > val)
        return search_in_BST(root->left, val);
    else
        return search_in_BST(root->right, val);
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    int x;
    cin >> x;

    if (search_in_BST(root, x))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}