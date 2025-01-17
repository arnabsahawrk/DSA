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

int depth(Node *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int left = depth(root->left);
    int right = depth(root->right);

    return max(left, right) + 1;
}

int count_nodes(Node *root)
{
    if (root == nullptr)
        return 0;

    int left = count_nodes(root->left);
    int right = count_nodes(root->right);

    return left + right + 1;
}

string perfect_binary_tree(Node *root)
{
    int maxDepth = depth(root);
    int totalNodes = count_nodes(root);


    return (pow(2, maxDepth) - 1) == totalNodes ? "YES" : "NO";
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    cout << perfect_binary_tree(root) << endl;

    return 0;
}