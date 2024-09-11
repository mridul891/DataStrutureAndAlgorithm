#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isSymmetricView(Node *left, Node *right)
{

    if (left == NULL || right == NULL)
        return left == right;

    if (left->val != right->val)
        return false;

    return isSymmetricView(left->left, right->right) && isSymmetricView(left->right, right->left);
}
bool isSymmetric(Node *root)
{
    if (root == NULL)
        return true;
    return isSymmetricView(root->left, root->right);
}
int main()
{
    return 0;
}