#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

ListNode *FindNewHead(ListNode *temp, int k)
{
    int count = 1;
    while (temp != NULL)
    {
        if (count == k)
            break;
        count++;
        temp = temp->next;
    }
    return temp;
}
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k == 0)
            return head;
        ListNode *tail = head;
        int length = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            length += 1;
        }
        cout << length;
        // if its is multiple of size of ll then on rotation it will give the
        // exact same ll
        if (k % length == 0)
            return head;

        k = k % length;

        tail->next = head;
        ListNode *newHead = FindNewHead(head, length - k);
        head = newHead->next;
        newHead->next = NULL;
        return head;
    }
};
int main()
{
}