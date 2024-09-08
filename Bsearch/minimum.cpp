#include <iostream>

using namespace std;

void minimum(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int ans = INT8_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[start] <= arr[mid])
        {
            ans = min(ans, arr[start]);
            start = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            end = mid - 1;
        }
    }
    cout << ans;
}
int main()
{
    int arr[] = {70, 80, 90, 110, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    minimum(arr, n);
}