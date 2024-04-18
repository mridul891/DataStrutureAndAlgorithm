#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextsmallerelement(int *arr, int size, vector<int> &ans)
{
    stack<int> st;
    st.push(-1);

    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }

        // yaha pe aa gaya toh uska matlab hai ki top element usse chota hi hoga jo ki hume chahiye
        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}
int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int size = 5;

    vector<int> ans(size);
    ans = nextsmallerelement(arr, size, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}