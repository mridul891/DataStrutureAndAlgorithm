#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void subsetsum(set<int> &ans, int index, vector<int> &arr, int sum, int size)
{

    if (index == size)
    {
        ans.insert(sum);
        return;
    }
    sum = sum + arr[index];
    subsetsum(ans, index + 1, arr, sum, size);
    sum = sum - arr[index];
    subsetsum(ans, index + 1, arr, sum, size);
}

int main()
{
    vector<int> arr{3,1,2};
    set<int> ans;
    int size = 3;
    int sum = 0;
    subsetsum(ans, 0, arr, sum, size);
    cout << "reached";
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    return 0;
}