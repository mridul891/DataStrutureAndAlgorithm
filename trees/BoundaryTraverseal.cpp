#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Following is the Binary Tree node structure:

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isleaf(TreeNode<int> *temp)
{
    if (temp->right == NULL && temp->left == NULL)
        return true;
    else
        return false;
}
void addleftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isleaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    vector<int> ans;
    while (curr)
    {
        if (!isleaf(curr))
            ans.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        res.push_back(ans[i]);
    }
}

void leaf(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *temp = root;
    if (isleaf(temp))
        res.push_back(temp->data);

    if (temp->left)
        leaf(temp->left, res);
    if (temp->right)
        leaf(temp->right, res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (root == NULL)
        return res;
    res.push_back(root->data);
    addleftBoundary(root, res);
    leaf(root, res);
    addRightBoundary(root, res);
    return res;
}
