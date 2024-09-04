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

Node *addTwono(Node *num1, Node *num2)
{
    Node *result = new Node(-1);
    Node *temp = result;
    int carry = 0;

    while (num1 != NULL || num2 != NULL)
    {
        int sum = carry;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;
        Node *newNode = new Node(sum);
        temp->next = newNode;
        temp = temp->next;
    }

    if (carry == 1){
        Node *newNode = new Node(1);
        temp->next = newNode;
        temp = temp->next;
    }

    return result->next;
}

int main()
{
    return 0;
}