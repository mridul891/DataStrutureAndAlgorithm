#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *getKthNode(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL && k >= 1)
    {
        k--;
        temp = temp->next;
    }

    return temp;
}

Node *kreverse(Node *head, int k)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        // Get THe Kth nODe 
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prev)
            {
                prev->next = temp;
            }
            break;
        }
        Node *nexty = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);

        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prev->next = kthNode;
        }
        prev = temp;
        temp = nexty;
    }
    return head;
}
int main()
{
}