#include <iostream>
#include <vector>
using namespace std;

int countsub(vector<int> &arr, int size, int sum, int k, int index)
{
    if (index == size)
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }

    sum = sum + arr[index];
    int l = countsub(arr, size, sum, k, index + 1);

    sum = sum - arr[index];
    int r = countsub(arr, size, sum, k, index + 1);

    return l + r;
}
int main()
{
    vector<int> arr{3, 1, 2, 4, 5};
    vector<int> subarr;
    int size = 5;
    int k = 6;
    int sum = 0;
    int ans = countsub(arr, size, sum, k, 0);
    cout << ans;
}