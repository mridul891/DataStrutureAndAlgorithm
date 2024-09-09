#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void Lside(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    Lside(root->left, level + 1, ans);
    Lside(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;

    Lside(root, 0, ans);
    return ans;
}