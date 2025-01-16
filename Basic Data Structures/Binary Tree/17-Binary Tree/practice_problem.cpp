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

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int main()
{
    Node *root = new Node(1);
    Node *a = new Node(7);
    Node *b = new Node(9);
    Node *c = new Node(2);
    Node *d = new Node(6);
    Node *e = new Node(5);
    Node *f = new Node(11);
    Node *g = new Node(9);
    Node *h = new Node(5);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    d->left = e;
    d->right = f;

    b->right = g;

    g->left = h;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}

/*
Preorder: 1->7->2->6->5->11->9->9->5
Inorder: 2->7->5->6->11->1->9->5->9
Postorder: 2->5->11->6->7->5->9->9->1
*/