#include <stack>
#include <iostream>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(int *arr, int size, vector<int> &ans)
{
    // Write your code here
    stack<int> st;
    st.push(-1);
    // int size = arr.size();
    // vector<int> ans(size);
    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && st.top() <= curr)
        {
            st.pop();
        }
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
    ans = nextGreaterElement(arr, size, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}