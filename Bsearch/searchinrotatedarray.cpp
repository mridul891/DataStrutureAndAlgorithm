#include <iostream>
using namespace std;

int searching(int arr[], int target, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
            return mid + 1;
        // finding which side is sorted Left or Right
        else if (arr[start] < arr[mid])
        {
            if (arr[start] <= target && target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target > arr[mid] && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 30, 70, 80, 90, 110};
    int n = sizeof(arr) / sizeof(arr[0]);
    int search = searching(arr, 110, n);
    cout << "The Element is Present at " << search;
}