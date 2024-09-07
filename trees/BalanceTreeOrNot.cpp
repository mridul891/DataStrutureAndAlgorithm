#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//  at any node If the leftHeight  - rightHeight  is less than or equal to 1 then it  is  balanced tree.

int HeightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    return 1 + max(lh + rh);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    if (abs(rh - lh) > 1)
        return false;

    bool leftBalanced = isBalanced(root->left);
    bool rightBalance = isBalanced(root->right);

    if (leftBalanced == false || rightBalanced == false)
        return false;
    return true;
}