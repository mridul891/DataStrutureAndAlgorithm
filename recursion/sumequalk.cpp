// int his problem we will find subsequence with the same sum equal to k
#include <iostream>
#include <vector>
using namespace std;

void sumeequalk(int index, vector<int> &arr, vector<int> &subarr, int size, int sum, int k)
{
    if (index == size)
    {
        if (sum == k)
        {
            for (auto i : subarr) cout << i << "  ";
            cout << endl;
        }
        return;
    }
    
    subarr.push_back(arr[index]);
    sum = sum + arr[index];
    sumeequalk(index + 1, arr, subarr, size, sum, k);
    sum = sum - arr[index];
    subarr.pop_back();
    sumeequalk(index + 1, arr, subarr, size, sum, k);
}
int main()
{
    vector<int> arr{3, 1, 2, 4, 5};
    vector<int> subarr;
    int size = 5;
    int k = 6;
    int sum = 0;
    sumeequalk(0, arr, subarr, size, sum, k);
}