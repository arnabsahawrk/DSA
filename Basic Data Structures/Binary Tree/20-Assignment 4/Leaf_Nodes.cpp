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

vector<int> leaf_nodes(Node *root)
{
    vector<int> v;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();

        if (node->left == nullptr && node->right == nullptr)
            v.push_back(node->value);

        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
    }

    sort(v.rbegin(), v.rend());

    return v;
}

int main()
{
    Node *root = nullptr;
    input_tree(root);

    vector<int> v = leaf_nodes(root);

    for (int val : v)
        cout << val << " ";

    return 0;
}