#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int noofstudents(int arr[], int pages, int n)
{
    int pagesstudent = 0;
    int students = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + pagesstudent <= pages)
        {
            pagesstudent = pagesstudent + arr[i];
        }
        else
        {
            pagesstudent = arr[i];
            students++;
        }
    }
    return students;
}
int findpage(int arr[], int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr, arr + n);
    cout << "the low is " << low << endl;
    int high = accumulate(arr, arr + n, 0);
    cout << "the high is " << high << endl;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int countstudent = noofstudents(arr, mid, n);
        if (countstudent > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peak = findpage(arr, n, 2);
    cout << "the answer is " << peak;
}