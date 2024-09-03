#include <iostream>
using namespace std;

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

Node *removeNFromBack(Node *head, int k)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    //  if we have to remove the last node from the back or in other word first node
    if (count == k)
    {
        Node *newNode = head->next;
        free(head);
        return newNode;
    }
    // remove other than first node
    int res = count - k;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);

    return head;
}

Node *removeNFromBack2(Node *head, int k)
{
    Node *fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    Node *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    if (fast == NULL)
        return head->next;
    Node *delNode = slow->next;
    slow = delNode->next;
    return head;
}

int main()
{
    return 0;
}