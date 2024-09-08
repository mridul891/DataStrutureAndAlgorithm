// This problem statement is used to find the first and last occurence of the number x
#include <iostream>
using namespace std;
void firstOccurence(int arr[], int x, int n)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "The first occurence of the number is " << ans + 1;
}

void lastoccurence(int arr[], int x, int n)
{
    int start = 0;
    int end = n - 1;
    int last = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << "the last occurence of x is" << last + 1;
}
int main()
{
    int arr[] = {1, 2, 3, 7, 8, 8, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    firstOccurence(arr, 8, n);
    lastoccurence(arr, 8, n);
}
