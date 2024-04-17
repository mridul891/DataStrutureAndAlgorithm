#include <iostream>
#include <stack>
using namespace std;
class specialStack
{
public:
    stack<int> st1, st2;
    void push(int data)
    {
        st1.push(data);
        if (st2.empty() || st2.top() > data)
        {
            st2.push(data);
        }
    }
    void pop()
    {
        if (st1.top() == st2.top())
        {
            st2.pop();
        }
        st1.pop();
    }
    int top()
    {
        return st1.top();
    }
    int getmin()
    {
        return st2.top();
    }
};