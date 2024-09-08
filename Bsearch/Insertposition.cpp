// In this question we have to insert the number in the correct index ;
#include <iostream>
using namespace std;

int indexing(int arr[], int target, int n)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < target)
        {
            ans = mid + 1;
            start = mid + 1;
        }
        else
        {
            ans = mid - 1;
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 7, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int answer = indexing(arr, 10, n);
    cout << "the answer is " << answer;
}