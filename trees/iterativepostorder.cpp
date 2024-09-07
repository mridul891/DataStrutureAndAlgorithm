#include <iostream>
#include <vector>
using namespace std;

vector<int> postorder(TreeNode *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<TreeNode *> stack1, stack2;
    stack1.push(root);
    while (!stack1.empty())
    {
        root = stack1.top();
        stack1.pop();
        stack2.push(root);
        if (root->left)
        {
            stack1.push(root->left);
        }
        if (root->right)
        {
            stack1.push(root->right);
        }
    }

    while (!stack2.empty())
    {
        postorder.push_back(stack2.top());
        stack2.pop();
    }
    return postorder;
}