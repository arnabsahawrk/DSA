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

int sum_without_leaf(Node *root)
{
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (root->left != nullptr || root->right != nullptr)
        sum += root->value;

    sum += sum_without_leaf(root->left);
    sum += sum_without_leaf(root->right);

    return sum;
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    cout << sum_without_leaf(root) << endl;

    return 0;
}