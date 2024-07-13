#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void findcom(int ind, int target, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int size)
{
    if (ind == size)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            for (auto i : ans)
            {
                for (auto j : ans)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        return;
    }

    // considering the element
    // add element to data structure
    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findcom(ind, target, ds, arr, ans, size);
        ds.pop_back();
    }
    // not considering the element
    findcom(ind + 1, target, ds, arr, ans, size);
}
int main()
{
    vector<vector<int>> ans;
    vector<int> arr{2, 3, 5, 7};
    vector<int> ds;
    int ind = 0;
    int size = 4;
    int target = 7;
    findcom(ind, target, ds, arr, ans, size);
    return 0;
}