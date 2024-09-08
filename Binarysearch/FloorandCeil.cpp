#include <iostream>
#include <utility>
using namespace std;

void floorandceil(int arr[], int target, int n)
{
    pair<int, int> ans;
    int start = 0;
    int end = n - 1;
    int floor = -1;
    int ceil = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }
        else if (arr[mid] < target)
        {
            ceil = arr[mid];
            start = mid + 1;
        }
        else
        {
            floor = arr[mid];
            end = mid - 1;
        }
    }
    cout << "ceil " << ceil << endl;
    cout << "floor" << floor;
}
int main()
{
    int arr[] = {10, 20, 30, 70, 80, 90, 110};
    int n = sizeof(arr) / sizeof(arr[0]);
    floorandceil(arr, 24, n);
    // cout << "the answer is " << answer;
}