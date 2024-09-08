#include <iostream>
using namespace std;
int findPeakElement(int arr[], int n)
{

    // Write your code here

    // for only sigle digit
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 1;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int start = 1;
    int end = n - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 6, 7, 9, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peak = findPeakElement(arr, n);
    cout << "the answer is " << peak;
}