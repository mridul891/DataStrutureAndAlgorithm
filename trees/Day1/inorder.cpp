#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void in(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    in(root->left);
    ans.push_back(root->data);
    in(root->right);
}
vector<int> inOrder(TreeNode<int> *root)
{
    in(root);
    return v;
}