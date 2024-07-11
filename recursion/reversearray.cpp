#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void reversearray(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return ;
    }
    swap(arr[low], arr[high]);
    return reversearray(arr, low + 1, high - 1);
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5};
    int low = 0;
    int high = 5 - 1;
    reversearray(arr, low, high);
    for (auto i : arr)
    {
        cout << i;
    }
}