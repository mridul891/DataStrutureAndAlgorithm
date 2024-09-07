#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int HeightOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = HeightOfTree(root->left);
    int rh = HeightOfTree(root->right);

    return 1 + max(lh + rh);
}