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

int max_height(Node *node)
{
    if (node == nullptr)
        return 0;

    if (node->left == nullptr && node->right == nullptr)
        return 0;

    int left = max_height(node->left);
    int right = max_height(node->right);

    return max(left, right) + 1;
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    cout << max_height(root) << endl;
    return 0;
}