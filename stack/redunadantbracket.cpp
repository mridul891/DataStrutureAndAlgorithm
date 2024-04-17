#include <iostream>
#include <stack>

using namespace std;

bool checkredundant(string &s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' || i == '+' || i == '-' || i == '*' || i == '/')
        {
            st.push(i);
        }
        else if (i == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // yaha pe tabhi pahuchhenge jab stack ke top mai ek openening bracket pdha hopga
            st.pop();

            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    string s = "((a+b)*(c+d))";
    bool ans = checkredundant(s);
    if (ans == true)
    {
        cout << "Redundant brackets are present" << endl;
    }
    else
    {
        cout << "Redundant Bracket   is not present " << endl;
    }
}