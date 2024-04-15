#include <iostream>
#include <stack>
using namespace std;

void insert(stack<int> &st, int &element)
{

    if (st.empty() || st.top() < element)
    {
        st.push(element);
        return;
    }

    // recursion
    int temp = st.top();
    st.pop();
    insert(st, element);

    // backtracking
    st.push(temp);
}

void sorts(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    sorts(st);

    insert(st, temp);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(3);
    st.push(40);
    st.push(50);
    st.push(2);
    // st.push(60);
    int data = 45;
    sorts(st);
    cout << "after" << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}