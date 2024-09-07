#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void inorderfunction(Node *root)
{
    if (root == NULL)
        return;
    inorderfunction(root->left);
    cout << root->val << endl;
    inorderfunction(root->right);
}
