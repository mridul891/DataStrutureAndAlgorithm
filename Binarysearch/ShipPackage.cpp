#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPossible(vector<int> &weights, int n, int mid)
    {
        int noofdays = 1;
        int weight = 0;

        for (int i = 0; i < n; i++)
        {
            if (weight + weights[i] <= mid)
            {
                weight += weights[i];
            }
            else
            {
                weight = weights[i];
                noofdays++;
            }
        }
        return noofdays;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();

        int start = 0, end = 0, ans;

        for (int i = 0; i < n; i++)
        {
            if (start <= weights[i])
            {
                start = weights[i];
            }
            end += weights[i];
        }

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int noofdays = isPossible(weights, n, mid);

            if (noofdays <= days)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};