#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//  *Definition for a binary tree node.
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
    int sums(TreeNode *temp, int &maxi)
    {
        if (temp == NULL)
            return 0;
        int lsum = max(0, sums(temp->left, maxi));
        int rsum = max(0, sums(temp->right, maxi));

        maxi = max(maxi, lsum + rsum + temp->val);

        return max(lsum, rsum) + temp->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        sums(root, maxi);
        return maxi;
    }
};