#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node *, int>> q;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int Level = it.second;

            mpp[Level] = node->data;

            if (node->left)
            {
                q.push({node->left, Level - 1});
            }
            if (node->right)
            {
                q.push({node->right, Level + 1});
            }
        }

        for (auto i : mpp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};