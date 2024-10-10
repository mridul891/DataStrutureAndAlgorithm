#include <bits/stdc++.h>
using namespace std;

long long isPossible(int arr[], int n, int k, long long mid)
{
    long long noOfpainter = 1;
    long long time = 0;

    for (long long i = 0; i < n; i++)
    {
        if (time + arr[i] <= mid)
        {
            time += arr[i];
        }
        else
        {
            time = arr[i];
            noOfpainter++;
        }
    }
    return noOfpainter;
}
long long minTime(int arr[], int n, int k)
{
    // if (k > n)
    //     return -1;

    long long start = 0, end = 0, ans;
    for (long long i = 0; i < n; i++)
    {
        if (start < arr[i])
        {
            start = arr[i];
        }
        end += arr[i];
    }

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        long long count = isPossible(arr, n, k, mid);
        if (count > k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
            ans = mid;
        }
    }
    return ans;
}