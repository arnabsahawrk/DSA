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

Node *convert_array_to_BST(int array[], int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    Node *root = new Node(array[mid]);

    Node *leftNode = convert_array_to_BST(array, left, mid - 1);
    Node *rightNode = convert_array_to_BST(array, mid + 1, right);

    root->left = leftNode;
    root->right = rightNode;

    return root;
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
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    Node *root = convert_array_to_BST(array, 0, n - 1);

    level_order_traversal(root);

    return 0;
}