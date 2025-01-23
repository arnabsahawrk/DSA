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

void print_outer_tree(Node *root, bool isLeft)
{
    if (root == nullptr)
        return;

    if (isLeft)
    {
        if (root->left)
            print_outer_tree(root->left, isLeft);
        else if (root->right)
            print_outer_tree(root->right, isLeft);

        cout << root->value << " ";
    }
    else
    {
        cout << root->value << " ";

        if (root->right)
            print_outer_tree(root->right, isLeft);
        else if (root->left)
            print_outer_tree(root->left, isLeft);
    }
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    print_outer_tree(root->left, true);
    cout << root->value << " ";
    print_outer_tree(root->right, false);

    return 0;
}