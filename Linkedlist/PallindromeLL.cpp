#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *temp)
{
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *nexty = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nexty;
    }

    return prev;
}

bool CheckPallindrom(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    // Find the middle Element

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newhead = reverse(slow->next);
    Node *temp = head;
    while (newhead != NULL)
    {
        if (temp->data != newhead->data)
        {
            reverse(newhead);
            return false;
        }

        temp = temp->next;
        newhead = newhead->next;
    }
    reverse(newhead);
    return true;
}
int main()
{
    return 0;
}