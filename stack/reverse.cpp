#include <iostream>
#include <stack>
using namespace std;
/* HEre we reverse the string usign stack */
int main()
{
    string str = "Mridul";
    stack<char> st;

    for (auto i : str)
    {
        st.push(i);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}