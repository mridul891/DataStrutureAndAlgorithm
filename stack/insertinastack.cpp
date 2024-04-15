#include <iostream>
#include <stack>
using namespace std;
// insert a element in a sorted stack
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

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int data = 45;
    insert(st, data);
    cout << "after" << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}