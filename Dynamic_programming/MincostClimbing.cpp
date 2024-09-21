#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution
{
public:
    int costy(int n, vector<int> &cost, vector<int> &dp)
    {
        // using dp top down approach
        if (n <= 1)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = min(cost[n - 1] + costy(n - 1, cost, dp),
                           cost[n - 2] + costy(n - 2, cost, dp));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // vector<int> dp(n + 1, -1);

        // Bottom up approach
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        // return costy(n, cost, dp);
        return dp[n];
    }
};