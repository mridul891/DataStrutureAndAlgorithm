#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void Pre(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    Pre(root->left);
    Pre(root->right);
}
vector<int> PreOrder(TreeNode<int> *root)
{
    Pre(root);
    return v;
}