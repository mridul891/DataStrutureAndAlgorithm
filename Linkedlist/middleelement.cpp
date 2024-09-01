#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Brute force method
Node *findMiddle(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int middle = (count / 2) + 1;
    while (middle > 1)
    {
        middle--;
        temp = temp->next;
    }
    return temp;
}
// optimal

// slow and fast pointer approach

Node *findMiddle2(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next == NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}