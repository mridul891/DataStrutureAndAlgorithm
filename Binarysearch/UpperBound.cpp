// Here lower Bound is defined as smallest index such that arr[index] >= x
#include <iostream>
#include <vector>
using namespace std;

int UpperBound(int arr[], int target, int n)
{
    int low = 0;
    int high = n - 1;
    int answer = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return answer;

    // TimeComplexity = O(logn)
}
int main()
{
    int arr[] = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    // Brute Force approach
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            cout << "The ans from the Brute Force solution is " << i << endl;
        }
    }
    // Time Complexity = O(n)

    // Best solution

    int answer = UpperBound(arr, x, n);
    cout << "the ans from the Best solution is" << answer << endl;
}