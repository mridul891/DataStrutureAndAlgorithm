#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();

    // recursion
    solve(st, data);

    // backtracking
    st.push(temp);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    // recursion
    int temp = st.top();
    st.pop();
    reverse(st);

    // backtracking
    solve(st, temp);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // int data = 400;
    reverse(st);
    cout << "after" << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}