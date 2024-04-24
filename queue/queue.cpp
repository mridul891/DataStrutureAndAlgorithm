#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = data;
        }
        else if (rear == size - 1)
        {
            cout << "cannot insert size is full";
            return;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop()
    {
        if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == -1 && rear == -1)
        {
            cout << "Underflow condition" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getsize()
    {
        return rear - front + 1;
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "No element Present" << endl;
            return -1;
        }
        return arr[front];
    }
    int getBack()
    {
        if (rear == -1)
        {
            cout << " No Element at the back " << endl;
            return -1;
        }
        return arr[rear];
    }
};
int main()
{
    Queue q(5);
    q.push(3);

    return 0;
}