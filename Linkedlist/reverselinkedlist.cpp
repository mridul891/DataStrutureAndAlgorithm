#include <iostream>
using namespace std;
#include <stack>
// BruteForce
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

Node *reverseLL(Node *head)
{
    // Write your code here.
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != head)
    {
        temp->data = st.top();
        st.pop();
    }
    return head;
}

// optimal solution

Node *reverseLL(Node *head)
{
    // Write your code here.
    Node *temp = head;
    Node *prev = NULL;
    Node *front = NULL;
    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// recursiver solution
Node *reverseLL(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *newhead = reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newhead;
}

int main()
{

    return 0;
}