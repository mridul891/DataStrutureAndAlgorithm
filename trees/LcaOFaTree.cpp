#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *lca(Node *root, Node *p, Node *q)
{

    if (root == NULL || root == p || root == q)
        return root;

    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    return root;
}

int main()
{
    return 0;
}