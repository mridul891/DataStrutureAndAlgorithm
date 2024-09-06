#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
//   Definition for linked list.
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next),
                                           child(child) {}
};

// Bruite force
Node *convert(vector<int> &ans, Node *head)
{
    if (ans.size() == 0)
        return NULL;
    head = new Node(ans[0]);
    Node *temp = head;
    for (int i = 1; i < ans.size(); i++)
    {
        Node *newNode = new Node(ans[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}
Node *flattenLinkedList(Node *head)
{
    // Write your code here
    Node *temp = head;
    vector<int> ans;

    while (temp != nullptr)
    {
        Node *temp2 = temp;
        while (temp2 != nullptr)
        {
            ans.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp = temp->next;
    }
    sort(ans.begin(), ans.end());
    Node *newHead = convert(ans, head);
    return newHead;
}

// Optimal way

Node *merge(Node *list1, Node *list2)
{

    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        res->next = NULL;
    }

    if (list1)
        res->child = list1;
    else
        res->child = list2;

    return dummyNode->child;
}

Node *flatten(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = flatten(head->next);
    head = merge(head, newHead);
    return head;
}