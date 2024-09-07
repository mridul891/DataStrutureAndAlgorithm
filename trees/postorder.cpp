#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void Post(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    Post(root->left);
    Post(root->right);
}
vector<int> PostOrder(TreeNode<int> *root)
{
    Post(root);
    return v;
}