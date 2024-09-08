// In this question we will find how many times does an array is rotated
#include <iostream>
using namespace std;

int rotation(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = INT8_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] < arr[high])
        {
            index = low;
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid])
        {
            index = low;
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            index = mid;
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    int arr[] = {70, 80, 90, 110, 130, 150, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotating = rotation(arr, n);
    cout << "The array is being rotated by " << rotating;
}