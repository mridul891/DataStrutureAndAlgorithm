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

// bruteforce
bool detectaLoop(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *temp = head;
    unordered_set<Node *> st;
    while (temp != NULL)
    {
        if (st.find(temp) != st.end())
        {
            return true;
        }

        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

// Optimal

bool DetectALoop2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}
