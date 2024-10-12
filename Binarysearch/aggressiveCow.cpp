#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPossible(vector<int> &stalls, int n, int mid)
    {
        int noOfcows = 1;
        int pos = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (pos + mid <= stalls[i])
            {
                noOfcows++;
                pos = stalls[i];
            }
        }
        return noOfcows;
    }
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here

        int start = 1, end = 0, ans;

        sort(stalls.begin(), stalls.end());

        end = stalls[n - 1] + stalls[0];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int noofCows = isPossible(stalls, n, mid);

            if (noofCows < k)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
        }

        return ans;
    }
};