// In thiswe will find the level order traversal of the  tre
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

vector<int> levelorder(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode<int>> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            ans.push_back(node->data);
        }
    }
}