#include <iostream>
using namespace std;

// Problem statement = Delete a given nOde when a node is given without knowing the head of the linked list

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

// Optimal
void Delete(Node *node)
{
    Node *Delnode = node;
    node->data = node->next->data;
    node->next = node->next->next;
    delete (Delnode->next);
}

int main()
{
    return 0;
}