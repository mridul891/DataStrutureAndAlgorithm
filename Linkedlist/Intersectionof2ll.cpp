#include <iostream>
using namespace std;
#include <set>
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

// brute force
Node *intersection(Node *head1, Node *head2)
{
    Node *temp2 = head2;

    while (temp2 != NULL)
    {
        Node *temp1 = head1;
        while (temp1 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    return NULL;
}
// optimal
Node *intersection2(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    Node *temp1 = head1;
    while (temp1 != NULL)
    {
        st.insert(temp1);
        temp1 = temp1->next;
    }

    Node *temp2 = head2;
    while (temp2 != NULL)
    {
        if (st.find(temp2) != st.end())
        {
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
}

// Best solution
Node *intersection3(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;

        if (temp1 == NULL)
        {
            temp1 = head2;
        }
        if (temp2 == NULL)
        {
            temp2 = head1;
        }
    }
    return NULL;
}
int main()
{
    return 0;
}