#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int maximum = INT_MIN;
int height(Node *temp)
{
    if (temp == NULL)
        return 0;

    int lh = height(temp->left);
    int rh = height(temp->right);

    return 1 + max(lh, rh);
}

int Diameter(Node *root)
{

    int lh = height(root->left);
    int rh = height(root->right);

    maximum = max(maximum, lh + rh);

    Diameter(root->left);
    Diameter(root->right);
}