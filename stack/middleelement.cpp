#include <iostream>
#include <stack>
using namespace std;
/* HEre we find the middle element of the stack */

void solve(stack<int> &st, int &pos, int &ans)
{
    if (pos == 1)
    {
        ans = st.top();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();

    // recursion
    solve(st, pos, ans);
    // backtracking
    st.push(temp);
}
int getMiddleElement(stack<int> &st)
{
    int pos = 0;
    if (st.empty())
    {
        cout << " the stack is empty" << endl;
        return -1;
    }
    int size = st.size();
    cout << size << endl;
    // to check whether the size is odd
    if (size % 2 != 0)
    {
        pos = (size / 2) + 1;
    }
    else
    {
        pos = size / 2;
    }

    int ans = -1;
    solve(st, pos, ans);
    return ans;
}
int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    int mid = getMiddleElement(st);
    cout << " the Middle element  is " << mid << endl;
    return 0;
}