#include <iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Brute force
Node *merge(Node *head1, Node *head2)
{
    vector<int> ans;
    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 != NULL)
    {
        ans.push_back(t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        ans.push_back(t2->data);
        t2 = t2->next;
    }

    sort(ans.begin(), ans.end());

    // convert the array to linked list

    Node *head = new Node(ans[0]);
    Node *temp = head;
    for (int i = 0; i < ans.size(); i++)
    {
        Node *new_node = new Node(ans[i]);
        temp->next = new_node;
    }
    return head;
}
// optimal way
Node *merge(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;

    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data <= t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
    {
        temp->next = t2;
    }
    return temp->next;
}
int main()
{
    return 0;
}