#include <iostream>
#include <stack>
using namespace std;
bool isvalid(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '{' || i == '(' || i == '[')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty())
            {
                if (i == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (i == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else if (i == ')' && st.top() == '(')
                {
                    st.pop();
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        cout << "true";
        return true;
    }
    else
    {
        cout << "false";
        return false;
    }
}

int main()
{
    string s = "[{]}";
    isvalid(s);
    return 0;
}