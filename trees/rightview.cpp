#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void rside(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (level == ans.size())
            ans.push_back(root->data);

        rside(root->right, level + 1, ans);
        rside(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        rside(root, 0, ans);
        return ans;
    }
};