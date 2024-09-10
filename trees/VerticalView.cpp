#include <bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int level = p.second.first;
            int vertices = p.second.second;

            mpp[vertices][level].insert(node->val);
            if (node->left)
                q.push({node->left, {level + 1, vertices - 1}});
            if (node->right)
                q.push({node->right, {level + 1, vertices + 1}});
        }

        vector<vector<int>> result;
        for (auto i : mpp)
        {
            vector<int> ans;
            for (auto j : i.second)
            {
                ans.insert(ans.end(), j.second.begin(), j.second.end());
            }
            result.push_back(ans);
        }
        return result;
    }
};