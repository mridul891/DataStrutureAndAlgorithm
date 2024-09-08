#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long calculatesum(vector<int> &arr, int first, int last)
{
    long long sum = 0;
    for (int index = first; index <= last; index++)
    {
        sum += arr[index];
    }
    return sum;
};
int main()
{
    // Write your code here.
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int n = 9;
    long long max = 0;
    long long first = 0;
    long long last = n - 1;
    while (first <= last)
    {
        long long ans = calculatesum(arr, first, last);
        // cout << ans << " ";
        if (ans > max)
        {
            max = ans;
            //  cout << ans << " ";
        }
        first++;
    }
    cout << max << endl;
    // return max;
    return 0;
}
